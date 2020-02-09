using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace assembler_test
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private string extractOpCode(string ins)
        {
            string code="";
            int index=ins.IndexOf(' ');
            string name = ins.Substring(0, index);
            if (name == "add"||name == "sub"||name == "or"||name == "and"||name == "sll"||name == "jr"||name == "slt")
            {
                code = "000000";
            }
            else if (name == "addi")
            {
                code = "001000";
            }
            else if (name == "andi")
            {
                code = "001100";
            }
            else if (name == "lw")
            {
                code = "100011";
            }
            else if (name == "sw")
            {
                code = "101011";
            }
            else if (name == "beq")
            {
                code = "000100";
            }
            else if (name == "j")
            {
                code = "000010";
            }
            else if (name == "jal")
            {
                code = "000011";
            }
            else if (name == "ori")
            {
                code = "001101";
            }
            return code;
        }

        private string registerCode(string regname)
        {
            string code="";
            /*individual registers*/
            if (regname == "zero")
            {
                code = "00000";
            }
            else if (regname == "sp")
            {
                code = "11101";
            }
            else if (regname == "ra")
            {
                code = "11111";
            }
            else if (regname == "at")
            {
                code = "00001";
            }
            else if (regname == "v0")
            {
                code = "00010";
            }
            else if (regname == "v1")
            {
                code = "00011";
            }
            else
            {
                /*collected registers*/
                if(regname[0]=='s')
                {
                    int first = 16;
                    int c = int.Parse(regname.Substring(1,1)) + first;
                    code = Convert.ToString(c, 2);
                }
                else if (regname[0] == 'a')
                {
                    int first = 4;
                    int c = int.Parse(regname.Substring(1,1)) + first;
                    code = Convert.ToString(c, 2);
                }
                else if (regname[0] == 't')
                {
                    int first = (int.Parse(regname.Substring(1, 1))) > 7 ? 16:8;///16 not 24 to avoid oveloading in c
                    int c = int.Parse(regname.Substring(1,1)) + first;
                    code = Convert.ToString(c, 2);
                }

            }
            //////
            /*what if the code length is less than 5??*/
            int lenght = code.Length;
            if(lenght<5)
            {
                int remain = 5 - lenght;
                for (int i =0; i<remain ; i++)
                {
                    code = "0" + code;
                }
            }


            return code;
        }

        private string insName(string ins)
        {
            int index = ins.IndexOf(' ');
            string name = ins.Substring(0, index);
            return name;
        }

        private string extractFirstReg(string ins)
        {
            string r = "";
            int index = ins.IndexOf('$');///start from regname 
            ////
            r = ins.Substring(index + 1, 2);
            if (r == "ze")
            {
                r = "zero";
            }
            return r;
        }

        private string extractSecondReg(string ins)
        {
            string r = "";
            int index = 0;
            int count = 0;
            ////
            for (int i = 0; i < ins.Length;i++ )
            {
                if (ins[i]=='$')
                {
                    count++;
                }
                ////
                if(count ==2)
                {
                    index = i;
                    break;
                }
            }
            ////
                r = ins.Substring(index + 1, 2);
            if (r == "ze")
            {
                r = "zero";
            }

            return r;
        }

        private string extractThirdReg(string ins)
        {
            string r = "";

            int index = ins.LastIndexOf('$');
            ///
            r = ins.Substring(index + 1, 2);

            if (r == "ze")
            {
                r = "zero";
            }

            return r;
        }

        private string extractFunc(string ins_name)
        {
            ////[ add - sw - lw - sll - and - or - beq - J - JAL - JR - addi - ori - slt]
            string func = "";
            if (ins_name == "add")
            {
                func = "100000";
            }
            else if (ins_name == "sll")
            {
                func = "000000";
            }
            else if (ins_name == "and")
            {
                func = "100100";
            }
            else if (ins_name == "or")
            {
                func = "100101";
            }
            else if (ins_name == "jr")
            {
                func = "001000";
            }
            else if (ins_name == "slt")
            {
                func = "101010";
            }
            else if (ins_name == "sub")
            {
                func = "100010";
            }


            return func;
        }

        private string extractShift(string ins)
        {
            string sh = "";
            int index = ins.LastIndexOf(',');
            int index1 = ins.LastIndexOf(';');
            string x = ins.Substring(index+1,index1-index-1);
            int value = int.Parse(x);

            sh = Convert.ToString(value, 2);


            /*what if the code length is less than 5??*/
            int lenght = sh.Length;
            if (lenght < 5)
            {
                int remain = 5 - lenght;
                for (int i = 0; i < remain; i++)
                {
                    sh = "0" + sh;
                }
            }

            return sh;
        }

        private string extract_16bit(string ins)
        {
            string sh = "";
            int index = ins.LastIndexOf(',');
            int index1 = ins.LastIndexOf(';');
            string x = ins.Substring(index + 1,index1-index-1);
            int value = int.Parse(x);

            sh = Convert.ToString(value, 2);


            /*what if the code length is less than 5??*/
            int lenght = sh.Length;
            if (lenght < 16)
            {
                int remain = 16 - lenght;
                for (int i = 0; i < remain; i++)
                {
                    sh = "0" + sh;
                }
            }
                /*handle -ve numbers*/
            else if (lenght == 32)
            {
                sh = sh.Substring(16);
            }

            return sh;
        }

        private string extractMemNum(string ins)
        {
            string r = "";
            int index1 = ins.IndexOf(',');
            int index2 = ins.IndexOf('(');

            int value = int.Parse(ins.Substring(index1+1,index2-index1-1));
            r = Convert.ToString(value, 2);
            /*
             making r in 16 bits*/

            int length = r.Length;
            if (length<16)
            {
                int remain = 16 - length;
                for (int i =0;i<remain;i++)
                {
                    r = "0" + r;
                }
            }
                /*handle -ve nubmers*/
            else if (length == 32)
            {
                r = r.Substring(16);
            }


            return r;
        }

         private string  handleKeyword(string ins)
        {
            string inst = "";
            int index = ins.IndexOf(':');
            int start = 0;
            for (int i = index + 1; i < ins.Length;i++)
            {
                if (ins[i]!=' ')
                {
                    start = i;
                    break;
                }
            }
            inst = ins.Substring(start);

                return inst;
        }

        private string extractJlabel(string ins)
         {
             string label = "";
            int start=0;
            int index = ins.IndexOf(' ');
            int end = ins.LastIndexOf(';');
            for (int i = index+1; i < ins.Length;i++)
            {
                if (ins[i]!=' ')
                {
                    start = i;
                    break;
                }
            }
            label = ins.Substring(start, end - start);

                return label;
         }
        
        private string removeLabelSpace(string ins)
        {
            string l = "";
            int end=ins.Length+1;
            for (int i = 0; i < ins.Length;i++)
            {
                if (ins[i]==' ')
                {
                    end = i;
                    break;
                }
            }
            l = ins.Substring(0,end-1);
                return l;
        }

        private int getLableAddress(string label, string[] arr, int arrsize)
        {
            int address = 0;
            for (int i = 0; i < arrsize;i++)
            {
                if(arr[i].Contains(':'))
                {
                    int ind= arr[i].IndexOf(':');
                    string x = removeLabelSpace(arr[i].Substring(0,ind));
                    if (x==label)
                    {
                        address = i;
                        break;
                    }


                }
                else
                {
                    continue;
                }
            }
                return address;
        }

        private string handleJAddress(int address)
        {
            string ad = "";
            ad = Convert.ToString(address, 2);

            /*make ad 32 bit*/
            if (ad.Length<32)
            {
                bool flag = false;
                int remain = 32 - ad.Length;
                if(address<0)
                {
                    flag = true;
                }
                for (int i = 0 ;i<remain ;i++)
                {
                    if (flag == true)
                    {
                        ad = '1' + ad;
                    }
                    else
                    {
                        ad = '0' + ad;
                    }
                }
            }

            //////////
            ad = ad.Substring(4, 26);

            return ad;
        }

        private string extractBeqLabel(string ins)
        {
            string label = "";
            int index = ins.LastIndexOf(',');
            for (int i = index + 1; i < ins.Length;i++)
            {
                if(ins[i]==' '||ins[i]==';')
                {
                    break;
                }
                else
                {
                    label += ins[i];
                }
            }
                return label;
        }

        private string handleBAddress(int address)
        {
            string ad = "";
            ad = Convert.ToString(address, 2);

            /*make ad 32 bit*/
            if (ad.Length < 16)
            {
                bool flag = false;
                int remain = 16 - ad.Length;
                if (address < 0)
                {
                    flag = true;
                }
                for (int i = 0; i < remain; i++)
                {
                    if (flag == true)
                    {
                        ad = '1' + ad;
                    }
                    else
                    {
                        ad = '0' + ad;
                    }
                }
            }
            else if (ad.Length==32)
            {
                ad = ad.Substring(16);
            }

            //////////

            return ad;

        }

        private string handleFirstSpace(string ins)
        {
            string inst = "";
            int start = 0;
            for(int i =0;i<ins.Length;i++)
            {
                if(ins[i]!=' ')
                {
                    start = i;
                    break;
                }
            }
            inst =ins.Substring(start);
            return inst;

        }

        ////////////C:\Users\Sala7\Desktop/MemF.txt
        ////////////vsim -c C:/Modeltech_pe_edu_10.4a/examples/work.mips do "run -all" 

       private void submit()
        {
            //opennig new file
            StreamWriter sw = new StreamWriter("E:\\InsMemoryFile.txt");
            try
            {
                /*filling array with lines in rich textbox*/
                string[] arr = new string[richTextBox1.Lines.Length-1];

                int itteration = richTextBox1.Lines.Length;
                int f = 0;
                for (int i = 0; i < itteration; i++)
                {
                    if (!richTextBox1.Lines[i].Contains(';'))
                    {
                        continue;
                    }
                    arr[f] = richTextBox1.Lines[i];
                    f++;
                }
                //////
                ////members
                string opCode;
                string instruction;
                string instruct;
                ////
                //opennig new file
                ////////////////// StreamWriter sw = new StreamWriter("C:\\Users\\Sala7\\Desktop//MemF.txt"); ;
                /*the main loop 
                 take every single line from RichTextBox and assemble it 
                 put it into file*/
                for (int i = 0; i < richTextBox1.Lines.Length-1; i++)
                {
                    /*remove any empty line!!*/
                    if (!richTextBox1.Lines[i].Contains(';'))
                    {
                        continue;
                    }

                    /*remove any spaces at the begining of the line*/
                    if (richTextBox1.Lines[i][0] == ' ')
                    {
                        instruct = handleFirstSpace(richTextBox1.Lines[i]);
                    }
                    else
                    {
                        instruct = richTextBox1.Lines[i];
                    }
                    /*handling existance of lable in instruction*/
                    if (instruct.Contains(':'))
                    {
                        instruction = handleKeyword(instruct);
                    }
                    else
                    {
                        instruction = instruct;
                    }

                    /*foreach line "instruction"
                     first we find out what type of ins is by getting the opcode*/
                    opCode = extractOpCode(instruction);


                    /*second if it's R format there will be algo
                     else will be alternative algo*/
                    if (opCode == "000000")////R-Format
                    {
                        string rs = "";
                        string rt = "";
                        string rd = "";
                        string sh = "";
                        string func = "";
                        string ins_name = insName(instruction);
                        /*handling diffrent cases of instructions
                         if instruction equal sll of jr algo is diff
                     
                         else rs gets second reg
                         rt gets third one & rd gets the first one*/


                        if (ins_name != "sll" && ins_name != "jr")
                        {
                            func = extractFunc(ins_name);
                            sh = "00000";
                            rs = registerCode(extractSecondReg(instruction));
                            rt = registerCode(extractThirdReg(instruction));
                            rd = registerCode(extractFirstReg(instruction));
                            sw.WriteLine(opCode + rs + rt + rd + sh + func);
                        }
                        else if (ins_name == "sll")
                        {
                            func = extractFunc(ins_name);
                            sh = extractShift(instruction);
                            rs = "00000";
                            rt = registerCode(extractSecondReg(instruction));
                            rd = registerCode(extractFirstReg(instruction));
                            sw.WriteLine(opCode + rs + rt + rd + sh + func);
                        }
                        else if (ins_name == "jr")
                        {
                            func = extractFunc(ins_name);
                            sh = "00000";
                            rs = registerCode(extractFirstReg(instruction));
                            rt = "00000";
                            rd = "00000";
                            sw.WriteLine(opCode + rs + rt + rd + sh + func);
                        }

                    }
                    /*third 
                     what if it wasn't R-Format,,,check if it is not j or jal so it's I-format*/
                    else
                    {
                        string ins_name = insName(instruction);

                        /*I-Format instruction*/
                        if (ins_name != "j" && ins_name != "jal")
                        {
                            string rs = "";
                            string rt = "";
                            string bits16 = "";
                            if (ins_name == "addi" || ins_name == "ori")
                            {
                                rs = registerCode(extractSecondReg(instruction));
                                rt = registerCode(extractFirstReg(instruction));
                                bits16 = extract_16bit(instruction);
                                sw.WriteLine(opCode + rs + rt + bits16);
                            }
                            /*lw sw have different implementation than other I-format instructions*/
                            else if (ins_name == "lw" || ins_name == "sw")
                            {
                                rt = registerCode(extractFirstReg(instruction));
                                rs = registerCode(extractThirdReg(instruction));/////third reg has same algo as memory reg
                                bits16 = extractMemNum(instruction);
                                sw.WriteLine(opCode + rs + rt + bits16);
                            }
                            /*beq has a different algo*/
                            else if (ins_name == "beq")
                            {
                                rt = registerCode(extractSecondReg(instruction));
                                rs = registerCode(extractFirstReg(instruction));/////third reg has same algo as memory reg
                                string label = extractBeqLabel(instruction);
                                int address = ((getLableAddress(label, arr, arr.Length)) - (i + 1));
                                bits16 = handleBAddress(address);
                                sw.WriteLine(opCode + rs + rt + bits16);
                            }

                        }
                        /*J-Format Instruction*/
                        else
                        {
                            string bits26 = "";
                            string label = extractJlabel(instruction);
                            int address = (getLableAddress(label, arr, arr.Length)) * 4;
                            bits26 = handleJAddress(address);
                            sw.WriteLine(opCode + bits26);
                        }

                    }


                }

                ////////////
                sw.Close();
                ////
                //MessageBox.Show("Finished \"\"\"Successfully\"\"\"");


                ///
                /*launching modelsim*/
                //string strCmdText;
                //strCmdText = "/C E:\\prog\\assembler_test\\code.bat";
                // System.Diagnostics.Process.Start("CMD.exe", strCmdText);

                


            }
            catch (Exception er)
            {
                sw.Close();
                //MessageBox.Show(er.ToString());
            }

            ////////////////


        }

        private void btn_submit_Click(object sender, EventArgs e)
        {
            //opennig new file
            StreamWriter sw = new StreamWriter("E:\\InsMemoryFile.txt");
            try
            {
                /*filling array with lines in rich textbox*/
                string[] arr = new string[richTextBox1.Lines.Length];

                
                int itteration=richTextBox1.Lines.Length;
                int f = 0;
                for (int i = 0; i < itteration; i++)
                {
                    if (!richTextBox1.Lines[i].Contains(';'))
                    {
                        continue;
                    }
                    arr[f] = richTextBox1.Lines[i];
                    f++;
                }
                //////
                ////members
                string opCode;
                string instruction;
                string instruct;
                ////
                //opennig new file
               ////////////////// StreamWriter sw = new StreamWriter("C:\\Users\\Sala7\\Desktop//MemF.txt"); ;
                /*the main loop 
                 take every single line from RichTextBox and assemble it 
                 put it into file*/
                for (int i = 0; i < richTextBox1.Lines.Length; i++)
                {
                    /*remove any empty line!!*/
                    if (!richTextBox1.Lines[i].Contains(';'))
                    {
                        continue;
                    }

                    /*remove any spaces at the begining of the line*/
                    if (richTextBox1.Lines[i][0] == ' ')
                    {
                        instruct = handleFirstSpace(richTextBox1.Lines[i]);
                    }
                    else
                    {
                        instruct = richTextBox1.Lines[i];
                    }
                    /*handling existance of lable in instruction*/
                    if (instruct.Contains(':'))
                    {
                        instruction = handleKeyword(instruct);
                    }
                    else
                    {
                        instruction = instruct;
                    }

                    /*foreach line "instruction"
                     first we find out what type of ins is by getting the opcode*/
                    opCode = extractOpCode(instruction);


                    /*second if it's R format there will be algo
                     else will be alternative algo*/
                    if (opCode == "000000")////R-Format
                    {
                        string rs = "";
                        string rt = "";
                        string rd = "";
                        string sh = "";
                        string func = "";
                        string ins_name = insName(instruction);
                        /*handling diffrent cases of instructions
                         if instruction equal sll of jr algo is diff
                     
                         else rs gets second reg
                         rt gets third one & rd gets the first one*/


                        if (ins_name != "sll" && ins_name != "jr")
                        {
                            func = extractFunc(ins_name);
                            sh = "00000";
                            rs = registerCode(extractSecondReg(instruction));
                            rt = registerCode(extractThirdReg(instruction));
                            rd = registerCode(extractFirstReg(instruction));
                            sw.WriteLine(opCode + rs + rt + rd + sh + func);
                        }
                        else if (ins_name == "sll")
                        {
                            func = extractFunc(ins_name);
                            sh = extractShift(instruction);
                            rs = "00000";
                            rt = registerCode(extractSecondReg(instruction));
                            rd = registerCode(extractFirstReg(instruction));
                            sw.WriteLine(opCode + rs + rt + rd + sh + func);
                        }
                        else if (ins_name == "jr")
                        {
                            func = extractFunc(ins_name);
                            sh = "00000";
                            rs = registerCode(extractFirstReg(instruction));
                            rt = "00000";
                            rd = "00000";
                            sw.WriteLine(opCode + rs + rt + rd + sh + func);
                        }

                    }
                    /*third 
                     what if it wasn't R-Format,,,check if it is not j or jal so it's I-format*/
                    else
                    {
                        string ins_name = insName(instruction);

                        /*I-Format instruction*/
                        if (ins_name != "j" && ins_name != "jal")
                        {
                            string rs = "";
                            string rt = "";
                            string bits16 = "";
                            if (ins_name == "addi" || ins_name == "ori")
                            {
                                rs = registerCode(extractSecondReg(instruction));
                                rt = registerCode(extractFirstReg(instruction));
                                bits16 = extract_16bit(instruction);
                                sw.WriteLine(opCode + rs + rt + bits16);
                            }
                            /*lw sw have different implementation than other I-format instructions*/
                            else if (ins_name == "lw" || ins_name == "sw")
                            {
                                rt = registerCode(extractFirstReg(instruction));
                                rs = registerCode(extractThirdReg(instruction));/////third reg has same algo as memory reg
                                bits16 = extractMemNum(instruction);
                                sw.WriteLine(opCode + rs + rt + bits16);
                            }
                            /*beq has a different algo*/
                            else if (ins_name == "beq")
                            {
                                rt = registerCode(extractSecondReg(instruction));
                                rs = registerCode(extractFirstReg(instruction));/////third reg has same algo as memory reg
                                string label = extractBeqLabel(instruction);
                                int address = ((getLableAddress(label, arr, arr.Length)) - (i + 1));
                                bits16 = handleBAddress(address);
                                sw.WriteLine(opCode + rs + rt + bits16);
                            }

                        }
                        /*J-Format Instruction*/
                        else
                        {
                            string bits26 = "";
                            string label = extractJlabel(instruction);
                            int address = (getLableAddress(label, arr, arr.Length)) * 4;
                            bits26 = handleJAddress(address);
                            sw.WriteLine(opCode + bits26);
                        }

                    }


                }

                ////////////
                sw.Close();
                ////
               
                //MessageBox.Show("Finished \"\"\"Successfully\"\"\"");
            

                ///
                /*launching modelsim*/
               //string strCmdText;
                //strCmdText = "/C E:\\prog\\assembler_test\\code.bat";
               // System.Diagnostics.Process.Start("CMD.exe", strCmdText);

                System.Diagnostics.Process process = new System.Diagnostics.Process();
                System.Diagnostics.ProcessStartInfo startInfo = new System.Diagnostics.ProcessStartInfo();
                startInfo.WindowStyle = System.Diagnostics.ProcessWindowStyle.Hidden;
                startInfo.FileName = "cmd.exe";
                startInfo.Arguments = "/C E:\\assembler_test\\code.bat";
                startInfo.Verb = "runas";
                process.StartInfo = startInfo;
                process.Start();
                System.Threading.Thread.Sleep(1500);


                /////
                /*put final state contents into rich boxes*/
                ///
                System.Threading.Thread.Sleep(2000);
                ////
                Form2 h = new Form2();
                h.ShowDialog();


                StreamReader pcF = new StreamReader("E:\\PC.txt");
                StreamReader RF = new StreamReader("E:\\RegFile.txt");
                StreamReader MF = new StreamReader("E:\\DataMemoryFile.txt");

                ///pc
                txt_pc.Text = "";
                //txt_pc.Text = File.ReadAllText("E:\\PC.txt");
                while (!pcF.EndOfStream)
                {
                    txt_pc.Text += pcF.ReadLine();
                    txt_pc.Text += "\n";
                }
                pcF.Close();
                ///
                
                //reg
                txt_reg.Text = "";
               // txt_reg.Text = File.ReadAllText("E:\\RegFile.txt");
                while (!RF.EndOfStream)
                {
                    txt_reg.Text += RF.ReadLine();
                    txt_reg.Text += "\n";
                }
                RF.Close();
                ////

                //mem
                txt_mem.Text = "";
                txt_mem.Text= File.ReadAllText("E:\\DataMemoryFile.txt");
                //int f = 0;
                //while (!MF.EndOfStream)
                //{
                //    txt_mem.Text += MF.ReadLine();
                //    txt_mem.Text += "\n";
                //    f++;
                //    if (f == 100) break;
                //}
                MF.Close();
                ////

               


            }
            catch(Exception er)
            {
                sw.Close();
                //MessageBox.Show(er.ToString());
                MessageBox.Show("Error");
            }

            ////////////////

           



        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {
        }

        private void btn_compare_Click(object sender, EventArgs e)
        {
           

        }

        private void btn_testCases_Click(object sender, EventArgs e)
        {
            numericUpDown1.Visible = true;
            label1.Visible = true;
            label2.Visible = true;
            txt_folderPath.Visible = true;
            btn_go.Visible = true;
            label3.Visible = true;
            rich_result.Visible = true;
            label4.Visible = true;
            btn_hide.Visible = true;
            lbl_process.Visible = true;
            txt_process.Visible = true;
        }

        private void btn_go_Click(object sender, EventArgs e)
        {

            int n =Convert.ToInt16(numericUpDown1.Value);///no of test cases
            string folderPath = txt_folderPath.Text;
            string[] result = new string[n];

            /*loop for every testcase and submit*/
            for (int i =1 ; i<=n;i++)
            {

                
                /*cases files*/
                StreamReader caseFile = new StreamReader(folderPath + "/TestCase" + i.ToString() + ".txt");
                StreamReader RegFile = new StreamReader(folderPath + "/RegF" + i.ToString() + ".txt");
                StreamReader MemFile = new StreamReader(folderPath + "/MemF" + i.ToString() + ".txt");

                

                /*put contents of test case file in rich text box to begin excution*/
                richTextBox1.Text = "";
                while (!caseFile.EndOfStream)
                {
                    richTextBox1.Text += caseFile.ReadLine();
                    richTextBox1.Text += "\n";
                }
                caseFile.Close();
                //////
                /*submit and convert which is in rich to binary and send it to
                 modelsim and run*/
                submit();
                //////

                txt_process.Text = i.ToString();
                System.Threading.Thread.Sleep(1000);
                /*run cmd*/
                System.Diagnostics.Process process = new System.Diagnostics.Process();
                System.Diagnostics.ProcessStartInfo startInfo = new System.Diagnostics.ProcessStartInfo();
                startInfo.WindowStyle = System.Diagnostics.ProcessWindowStyle.Hidden;
                startInfo.FileName = "cmd.exe";
                startInfo.Arguments = "/C E:\\assembler_test\\code.bat";
                startInfo.Verb = "runas";
                process.StartInfo = startInfo;
                System.Threading.Thread.Sleep(1500);
                process.Start();
                
                System.Threading.Thread.Sleep(2000);
                txt_process.Text = i.ToString();
                
                //////
                //System.Threading.Thread.Sleep(2000);

                /*modelsim files*/
                StreamReader modelsimReg = new StreamReader("E:\\RegFile.txt");
                StreamReader modelsimMem = new StreamReader("E:\\DataMemoryFile.txt");
                //////
                txt_process.Text = i.ToString();
                /*compare two reg files*/
                int flagr = 1;
                while(!RegFile.EndOfStream)
                {
                    if (RegFile.ReadLine().Substring(0,32) != modelsimReg.ReadLine().Substring(0,32))
                    {
                        flagr = 0;
                        break;
                    }
                }
                RegFile.Close();
                modelsimReg.Close();

                /*compare two mem files*/
                int flagm = 1;
                while (!MemFile.EndOfStream)
                {
                    if (MemFile.ReadLine().Substring(0, 32) != modelsimMem.ReadLine().Substring(0, 32))
                    {
                        flagm = 0;
                        break;
                    }
                }
                MemFile.Close();
                modelsimMem.Close();
                ////
                /*check for both files are correct*/
                if (flagr==1 && flagm==1)
                {
                    result[i - 1] = "Test " + i.ToString() + " is Successful";
                }
                else
                {
                    result[i - 1] = "Test " + i.ToString() + " is failed";
                }

                txt_process.Text = i.ToString();
                

            }
            rich_result.Text = "";
            for (int j =0; j<n;j++)
            {
                rich_result.Text += result[j];
                rich_result.Text += "\n";
            }

            /*finish*/
            Form3 m = new Form3();
            m.ShowDialog();

        }

        private void btn_hide_Click(object sender, EventArgs e)
        {
            numericUpDown1.Visible = false;
            label1.Visible = false;
            label2.Visible = false;
            txt_folderPath.Visible = false;
            btn_go.Visible = false;
            label3.Visible = false;
            rich_result.Visible = false;
            label4.Visible = false;
            btn_hide.Visible = false;
            lbl_process.Visible = false;
            txt_process.Visible = false;
        }

        


        
    }
}
