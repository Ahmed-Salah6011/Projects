namespace assembler_test
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.btn_submit = new System.Windows.Forms.Button();
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            this.numericUpDown1 = new System.Windows.Forms.NumericUpDown();
            this.btn_testCases = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.txt_folderPath = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.btn_go = new System.Windows.Forms.Button();
            this.rich_result = new System.Windows.Forms.RichTextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.btn_hide = new System.Windows.Forms.Button();
            this.txt_mem = new System.Windows.Forms.RichTextBox();
            this.txt_reg = new System.Windows.Forms.RichTextBox();
            this.txt_pc = new System.Windows.Forms.RichTextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.lbl_process = new System.Windows.Forms.Label();
            this.txt_process = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).BeginInit();
            this.SuspendLayout();
            // 
            // btn_submit
            // 
            this.btn_submit.BackColor = System.Drawing.Color.Bisque;
            this.btn_submit.Font = new System.Drawing.Font("Monotype Corsiva", 21.75F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_submit.ForeColor = System.Drawing.Color.Brown;
            this.btn_submit.Location = new System.Drawing.Point(493, 15);
            this.btn_submit.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btn_submit.Name = "btn_submit";
            this.btn_submit.Size = new System.Drawing.Size(157, 54);
            this.btn_submit.TabIndex = 1;
            this.btn_submit.Text = "Submit";
            this.btn_submit.UseVisualStyleBackColor = false;
            this.btn_submit.Click += new System.EventHandler(this.btn_submit_Click);
            // 
            // richTextBox1
            // 
            this.richTextBox1.BackColor = System.Drawing.Color.LightYellow;
            this.richTextBox1.Font = new System.Drawing.Font("Segoe UI Semibold", 12F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.richTextBox1.Location = new System.Drawing.Point(14, 15);
            this.richTextBox1.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.Size = new System.Drawing.Size(391, 819);
            this.richTextBox1.TabIndex = 2;
            this.richTextBox1.Text = "";
            this.richTextBox1.TextChanged += new System.EventHandler(this.richTextBox1_TextChanged);
            // 
            // numericUpDown1
            // 
            this.numericUpDown1.BackColor = System.Drawing.Color.LightYellow;
            this.numericUpDown1.ForeColor = System.Drawing.Color.SaddleBrown;
            this.numericUpDown1.Location = new System.Drawing.Point(1027, 544);
            this.numericUpDown1.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.numericUpDown1.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDown1.Name = "numericUpDown1";
            this.numericUpDown1.Size = new System.Drawing.Size(49, 24);
            this.numericUpDown1.TabIndex = 3;
            this.numericUpDown1.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDown1.Visible = false;
            // 
            // btn_testCases
            // 
            this.btn_testCases.BackColor = System.Drawing.Color.Bisque;
            this.btn_testCases.Font = new System.Drawing.Font("Monotype Corsiva", 21.75F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_testCases.ForeColor = System.Drawing.Color.Brown;
            this.btn_testCases.Location = new System.Drawing.Point(661, 481);
            this.btn_testCases.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btn_testCases.Name = "btn_testCases";
            this.btn_testCases.Size = new System.Drawing.Size(313, 54);
            this.btn_testCases.TabIndex = 4;
            this.btn_testCases.Text = "Submit Test Cases";
            this.btn_testCases.UseVisualStyleBackColor = false;
            this.btn_testCases.Click += new System.EventHandler(this.btn_testCases_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Transparent;
            this.label1.Font = new System.Drawing.Font("Monotype Corsiva", 14.25F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label1.Location = new System.Drawing.Point(853, 540);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(170, 28);
            this.label1.TabIndex = 5;
            this.label1.Text = "No of Test Cases";
            this.label1.Visible = false;
            // 
            // txt_folderPath
            // 
            this.txt_folderPath.BackColor = System.Drawing.Color.LightYellow;
            this.txt_folderPath.Location = new System.Drawing.Point(865, 582);
            this.txt_folderPath.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.txt_folderPath.Name = "txt_folderPath";
            this.txt_folderPath.Size = new System.Drawing.Size(220, 24);
            this.txt_folderPath.TabIndex = 6;
            this.txt_folderPath.Visible = false;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.Color.Transparent;
            this.label2.Font = new System.Drawing.Font("Monotype Corsiva", 14.25F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label2.Location = new System.Drawing.Point(739, 580);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(126, 28);
            this.label2.TabIndex = 7;
            this.label2.Text = "Folder Path";
            this.label2.Visible = false;
            // 
            // btn_go
            // 
            this.btn_go.BackColor = System.Drawing.Color.Bisque;
            this.btn_go.Font = new System.Drawing.Font("Monotype Corsiva", 21.75F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_go.ForeColor = System.Drawing.Color.Brown;
            this.btn_go.Location = new System.Drawing.Point(493, 762);
            this.btn_go.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btn_go.Name = "btn_go";
            this.btn_go.Size = new System.Drawing.Size(107, 54);
            this.btn_go.TabIndex = 8;
            this.btn_go.Text = "GO";
            this.btn_go.UseVisualStyleBackColor = false;
            this.btn_go.Visible = false;
            this.btn_go.Click += new System.EventHandler(this.btn_go_Click);
            // 
            // rich_result
            // 
            this.rich_result.BackColor = System.Drawing.Color.LightYellow;
            this.rich_result.Location = new System.Drawing.Point(694, 657);
            this.rich_result.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.rich_result.Name = "rich_result";
            this.rich_result.Size = new System.Drawing.Size(200, 177);
            this.rich_result.TabIndex = 9;
            this.rich_result.Text = "";
            this.rich_result.Visible = false;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.Color.Transparent;
            this.label3.Font = new System.Drawing.Font("Monotype Corsiva", 18F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label3.Location = new System.Drawing.Point(727, 619);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(128, 37);
            this.label3.TabIndex = 10;
            this.label3.Text = "RESULT";
            this.label3.Visible = false;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.BackColor = System.Drawing.Color.Transparent;
            this.label4.Font = new System.Drawing.Font("Monotype Corsiva", 14.25F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label4.Location = new System.Drawing.Point(994, 690);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(329, 140);
            this.label4.TabIndex = 11;
            this.label4.Text = "Make sure that\r\nTest case file name is : TestCaseN\r\nReg file name is : RegFN\r\nMem" +
    " file name is : MemN\r\n\"While N is the number of file\"";
            this.label4.Visible = false;
            // 
            // btn_hide
            // 
            this.btn_hide.BackColor = System.Drawing.Color.Bisque;
            this.btn_hide.Font = new System.Drawing.Font("Monotype Corsiva", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_hide.ForeColor = System.Drawing.Color.Brown;
            this.btn_hide.Location = new System.Drawing.Point(928, 693);
            this.btn_hide.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btn_hide.Name = "btn_hide";
            this.btn_hide.Size = new System.Drawing.Size(29, 39);
            this.btn_hide.TabIndex = 12;
            this.btn_hide.Text = "^ ";
            this.btn_hide.UseVisualStyleBackColor = false;
            this.btn_hide.Visible = false;
            this.btn_hide.Click += new System.EventHandler(this.btn_hide_Click);
            // 
            // txt_mem
            // 
            this.txt_mem.BackColor = System.Drawing.Color.LightYellow;
            this.txt_mem.Location = new System.Drawing.Point(1066, 132);
            this.txt_mem.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.txt_mem.Name = "txt_mem";
            this.txt_mem.Size = new System.Drawing.Size(313, 363);
            this.txt_mem.TabIndex = 13;
            this.txt_mem.Text = "";
            // 
            // txt_reg
            // 
            this.txt_reg.BackColor = System.Drawing.Color.LightYellow;
            this.txt_reg.Location = new System.Drawing.Point(739, 132);
            this.txt_reg.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.txt_reg.Name = "txt_reg";
            this.txt_reg.Size = new System.Drawing.Size(321, 291);
            this.txt_reg.TabIndex = 14;
            this.txt_reg.Text = "";
            // 
            // txt_pc
            // 
            this.txt_pc.BackColor = System.Drawing.Color.LightYellow;
            this.txt_pc.Enabled = false;
            this.txt_pc.Location = new System.Drawing.Point(413, 133);
            this.txt_pc.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.txt_pc.Name = "txt_pc";
            this.txt_pc.Size = new System.Drawing.Size(321, 37);
            this.txt_pc.TabIndex = 15;
            this.txt_pc.Text = "";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.BackColor = System.Drawing.Color.Transparent;
            this.label5.Font = new System.Drawing.Font("Monotype Corsiva", 15.75F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.ForeColor = System.Drawing.Color.Bisque;
            this.label5.Location = new System.Drawing.Point(488, 97);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(172, 33);
            this.label5.TabIndex = 16;
            this.label5.Text = "PC Final State";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.BackColor = System.Drawing.Color.Transparent;
            this.label6.Font = new System.Drawing.Font("Monotype Corsiva", 15.75F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.ForeColor = System.Drawing.Color.Bisque;
            this.label6.Location = new System.Drawing.Point(786, 97);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(229, 33);
            this.label6.TabIndex = 17;
            this.label6.Text = "Reg File Final State";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.BackColor = System.Drawing.Color.Transparent;
            this.label7.Font = new System.Drawing.Font("Monotype Corsiva", 15.75F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.ForeColor = System.Drawing.Color.Bisque;
            this.label7.Location = new System.Drawing.Point(1129, 97);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(207, 33);
            this.label7.TabIndex = 18;
            this.label7.Text = "MEM Final State";
            // 
            // lbl_process
            // 
            this.lbl_process.AutoSize = true;
            this.lbl_process.BackColor = System.Drawing.Color.Transparent;
            this.lbl_process.Font = new System.Drawing.Font("Monotype Corsiva", 14.25F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_process.ForeColor = System.Drawing.Color.Maroon;
            this.lbl_process.Location = new System.Drawing.Point(1087, 582);
            this.lbl_process.Name = "lbl_process";
            this.lbl_process.Size = new System.Drawing.Size(205, 28);
            this.lbl_process.TabIndex = 20;
            this.lbl_process.Text = "Processing Test Case";
            this.lbl_process.Visible = false;
            // 
            // txt_process
            // 
            this.txt_process.BackColor = System.Drawing.Color.LightYellow;
            this.txt_process.Enabled = false;
            this.txt_process.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txt_process.ForeColor = System.Drawing.Color.Maroon;
            this.txt_process.Location = new System.Drawing.Point(1291, 585);
            this.txt_process.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.txt_process.Name = "txt_process";
            this.txt_process.Size = new System.Drawing.Size(35, 24);
            this.txt_process.TabIndex = 21;
            this.txt_process.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.txt_process.Visible = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Gray;
            this.BackgroundImage = global::assembler_test.Properties.Resources.wal;
            this.ClientSize = new System.Drawing.Size(1403, 850);
            this.Controls.Add(this.txt_process);
            this.Controls.Add(this.lbl_process);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.txt_pc);
            this.Controls.Add(this.txt_reg);
            this.Controls.Add(this.txt_mem);
            this.Controls.Add(this.btn_hide);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.rich_result);
            this.Controls.Add(this.btn_go);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.txt_folderPath);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.btn_testCases);
            this.Controls.Add(this.numericUpDown1);
            this.Controls.Add(this.richTextBox1);
            this.Controls.Add(this.btn_submit);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "MIPS Assembler";
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btn_submit;
        private System.Windows.Forms.RichTextBox richTextBox1;
        private System.Windows.Forms.NumericUpDown numericUpDown1;
        private System.Windows.Forms.Button btn_testCases;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txt_folderPath;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button btn_go;
        private System.Windows.Forms.RichTextBox rich_result;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button btn_hide;
        private System.Windows.Forms.RichTextBox txt_mem;
        private System.Windows.Forms.RichTextBox txt_reg;
        private System.Windows.Forms.RichTextBox txt_pc;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label lbl_process;
        private System.Windows.Forms.TextBox txt_process;
    }
}

