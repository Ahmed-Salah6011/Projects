import tkinter as tk
from tkinter import ttk
import tkinter.messagebox

###virtual databases
DB_users = {"1600171" : "Ahmed Salah" , "1600012":"Ibrahim Atef" , "1600966" : "Fatma Elzahraa"}
DB_clients = []
DB_reservations= []


###system classes
class User:
    def set_name(self,n):
        self.name=n

    def get_name(self):
        return self.name

    def set_id(self,i):
        self.id=i

    def get_id(self):
        return self.id

class Client:

    def set_name(self,n):
        self.__name = n

    def get_name(self):
        return self.__name


    def set_age(self,n):
        self.__age = n

    def get_age(self):
        return self.__age

    def set_id(self,n):
        self.__id = n

    def get_id(self):
        return self.__id

    def set_phone(self,n):
        self.__phone = n

    def get_phone(self):
        return self.__phone

    def set_gender(self,n):
        self.__gender = n

    def get_gender(self):
        return self.__gender


class Reservation:
    __endDate = "Open"
    def set_client(self,n):
        self.__client = n

    def get_client(self):
        return self.__client

    def set_roomSize(self,n):
        self.__roomSize = n

    def get_roomSize(self):
        return self.__roomSize

    def set_roomType(self,n):
        self.__roomType = n

    def get_roomType(self):
        return self.__roomType

    def set_roomLocation(self,n):
        self.__roomLocation = n

    def get_roomLocation(self):
        return self.__roomLocation

    def set_bedsNo(self,n):
        self.__bedsNo = n

    def get_bedsNo(self):
        return self.__bedsNo

    def set_startDate(self,n):
        self.__startDate = n

    def get_startDate(self):
        return self.__startDate

    def set_endDate(self,n):
        self.__endDate = n

    def get_endDate(self):
        return self.__endDate

    def set_package(self, n):
        self.__package = n

    def get_package(self):
        return self.__package


class Package:
    __packageName = "None"
    __packagePrice = 0

    def set_packageName(self,n):
        self.__packageName = n

    def get_packageName(self):
        return self.__packageName

    def set_packagePrice(self,n):
        self.__packagePrice = n

    def get_packagePrice(self):
        return self.__packagePrice


########

######gui classes
class controller(tk.Tk):
    def __init__(self,*args,**kwargs):
        tk.Tk.__init__(self,*args , **kwargs)

        container = tk.Frame(self)
        container.pack(side = "top" , fill = "both" ,expand =True)

        self.frames={}

        for F in (loginPage , addUserPage , mainPage,personalData,bookingData,packagePage,pricePage,viewPage,delete_checkoutPage):
            fr = F(container ,self)
            self.frames[F] = fr
            fr.grid(row = 0 ,column =0 , sticky = "nsew")

        self.show_page(loginPage)

    def show_page(self,page):
        p = self.frames[page]
        p.tkraise()

    def clearAll(self):
        self.frames[personalData].clear()
        self.frames[bookingData].clear()

    def change_mainPage_label(self,txt):
        self.frames[mainPage].change_username_Label(txt)

    def set_client_inBookingData(self,c):
        self.frames[bookingData].set_client(c)

    def set_reservation_inPackagePage(self,r):
        self.frames[packagePage].set_reservation(r)

    def set_reservation_inPricePage(self,r):
        self.frames[pricePage].set_reservation(r)

    def change_pricePage_label(self,txt):
        self.frames[pricePage].change_labelPrice(txt)

    def fill_data_in_tree(self):
        self.frames[viewPage].fill_tree()
        self.frames[delete_checkoutPage].fill_tree()

class loginPage(tk.Frame):
    def __init__(self,parent,controller):
        tk.Frame.__init__(self,parent)

        self.lbl_id = tk.Label(self , text  = "User ID")
        self.lbl_id.grid(row =0 , column =0 , padx = 10 , pady = 5)

        self.entry_id =tk.Entry(self)
        self.entry_id.grid(row =0 , column = 1)

        self.btn_login = tk.Button(self, text= "Login" , command = lambda : self.click_login(controller))
        self.btn_login.grid(row = 1 , column = 2)

        self.btn_addUser = tk.Button(self, text = "Add User" , command = lambda :self.click_add(controller))
        self.btn_addUser.grid(row = 1 , column = 5, padx=10)



    def click_add(self,controller):
        self.entry_id.delete(0, "end")
        controller.show_page(addUserPage)


    def click_login(self,controller):
        id = self.entry_id.get()

        if(DB_users.__contains__(id)):
            self.entry_id.delete(0, "end")
            controller.change_mainPage_label("User: "+DB_users[id])
            controller.show_page(mainPage)
        else:
            tkinter.messagebox.showerror("Wrong Access" , "ID is not valid")

class addUserPage(tk.Frame):
    def __init__(self,parent,controller):
        tk.Frame.__init__(self,parent)

        self.lbl_name = tk.Label(self,text = "Name")
        self.lbl_name.grid(row =0 , column = 0)

        self.lbl_id = tk.Label(self, text="ID")
        self.lbl_id.grid(row=1, column=0)

        self.entry_name = tk.Entry(self)
        self.entry_name.grid(row =0 ,column = 1)

        self.entry_id = tk.Entry(self)
        self.entry_id.grid(row=1, column=1)

        self.btn_submit = tk.Button(self,text = "Submit" , command = lambda :self.click_submit(controller))
        self.btn_submit.grid(row = 2 , column = 2)

        self.btn_cancel = tk.Button(self, text="Cancel", command=lambda: self.click_cancel(controller))
        self.btn_cancel.grid(row=2, column=3 , padx = 10)


    def click_submit(self,controller):
        qu = tkinter.messagebox.askyesno("Verification" , "Are you sure you want to submit ?")
        if (qu == True):
            name = self.entry_name.get()
            id = self.entry_id.get()
            DB_users[id] = name
            self.entry_id.delete(0, "end")
            self.entry_name.delete(0, "end")
            controller.show_page(loginPage)

    def click_cancel(self,controller):
        self.entry_id.delete(0, "end")
        self.entry_name.delete(0, "end")
        controller.show_page(loginPage)

class mainPage(tk.Frame):
    def __init__(self,parent,controller):
        tk.Frame.__init__(self,parent)

        ##functions missing

        self.btn_add = tk.Button(self, text="Add Reservation", command=lambda: self.click_add(controller))
        self.btn_add.grid(row=0, column=2)

        self.btn_delete = tk.Button(self, text="Delete/Checkout ", command=lambda: self.click_delete(controller))
        self.btn_delete.grid(row=1, column=2)

        self.btn_view = tk.Button(self, text="View Reservations", command=lambda: self.click_view(controller))
        self.btn_view.grid(row=2, column=2)

        self.btn_logout = tk.Button(self, text="Logout", command=lambda: self.click_logout(controller))
        self.btn_logout.grid(row=3, column=4)

        self.lbl_username = tk.Label(self,text = "name",anchor = "w")
        self.lbl_username.grid(row=0 , column =10 , sticky = "w")

    def click_logout(self,controller):
        controller.show_page(loginPage)

    def click_add(self,controller):
        controller.show_page(personalData)

    def click_delete(self,controller):
        controller.fill_data_in_tree()
        controller.show_page(delete_checkoutPage)

    def click_view(self,controller):
        controller.fill_data_in_tree()
        controller.show_page(viewPage)

    def change_username_Label(self,txt):
        self.lbl_username.configure(text = txt)

class personalData(tk.Frame):
    def __init__(self,parent , controller):
        tk.Frame.__init__(self,parent)
        #######Labels
        self.lbl_name = tk.Label(self, text = "Name")
        self.lbl_name.grid(row =0 , column =0)

        self.lbl_age = tk.Label(self, text="Age")
        self.lbl_age.grid(row=1, column=0)

        self.lbl_id = tk.Label(self, text="National ID")
        self.lbl_id.grid(row=2, column=0)

        self.lbl_phone = tk.Label(self, text="Phone No.")
        self.lbl_phone.grid(row=3, column=0)

        ###########

        #########Entries
        self.entry_name = tk.Entry(self)
        self.entry_name.grid(row=0, column=1)

        self.entry_age = tk.Entry(self)
        self.entry_age.grid(row=1, column=1)

        self.entry_id = tk.Entry(self)
        self.entry_id.grid(row=2, column=1)

        self.entry_phone = tk.Entry(self)
        self.entry_phone.grid(row=3, column=1)
        #######

        ###radiobuttons
        self.rbtn_male = ttk.Radiobutton(self,text = "Male")
        self.rbtn_male.grid(row = 4 ,column = 0)

        self.rbtn_female = ttk.Radiobutton(self, text="Female")
        self.rbtn_female.grid(row=4, column=1)


        self.rbValue = tk.StringVar()
        self.rbtn_male.config(variable = self.rbValue , value = "Male")
        self.rbtn_female.config(variable=self.rbValue, value="Female")

        ###########
        self.btn_next = tk.Button(self,text= "Next" , command = lambda : self.click_next(controller))
        self.btn_next.grid(row = 5 , column = 5 , padx=5)

        self.btn_back = tk.Button(self, text="Back", command=lambda: self.click_back(controller))
        self.btn_back.grid(row=5, column=2 , padx = 5)


    def clear(self):
        self.entry_id.delete(0,"end")
        self.entry_phone.delete(0,"end")
        self.entry_name.delete(0,"end")
        self.entry_age.delete(0,"end")


    def click_next(self,controller):
        name =self.entry_name.get()
        age = self.entry_age.get()
        phone = self.entry_phone.get()
        id = self.entry_id.get()
        gender = self.rbValue.get()
        flag =0
        error =""

        if(name != "" and age != "" and id != "" and phone != "" and gender != ""):

            if ((len(id) <14 or len(id)>14) or (self.contains_letter(id) == True)):
                flag=1
                self.entry_id.configure(fg ="red")
                error+= "National ID must be 14 numbers\n"

            if ((int(age) < 18) or(self.contains_letter(age) == True)):
                flag=1
                self.entry_age.configure(fg="red")
                error+="Age must be greater than 18\n"

            if (((len(phone)<11 or len(phone)>11) or phone[0] != '0') or (self.contains_letter(phone) == True)):
                flag=1
                self.entry_phone.configure(fg="red")
                error+="Phone number must be 11 numbers starts with '0'\n"

            if (flag ==0):
                client =Client()
                client.set_name(name)
                client.set_age(age)
                client.set_id(id)
                client.set_phone(phone)
                client.set_gender(gender)
                controller.set_client_inBookingData(client)

                controller.show_page(bookingData)

            else:
                tkinter.messagebox.showinfo("Wrong Data" , error)

        else:
            flag =1
            tkinter.messagebox.showinfo("Wrong Data","Please fill in all the required info to proceed")

    def click_back(self,controller):
        self.entry_name.delete(0, "end")
        self.entry_id.delete(0, "end")
        self.entry_phone.delete(0, "end")
        self.entry_age.delete(0,"end")
        controller.show_page(mainPage)


    def contains_letter(self,txt):
        for i in txt:
            if (( i >='a' and i <='z') or (i >='A' and i<='Z')):
                return True

        return False

class bookingData(tk.Frame):
    client =Client()
    client.set_name("")
    client.set_gender("")
    client.set_phone(0)
    client.set_id(0)
    client.set_age(0)

    def __init__(self,parent,controller):
        tk.Frame.__init__(self,parent)

        #####label
        self.lbl_start = tk.Label(self,text = "Start From: ")
        self.lbl_start.grid(row =0 ,column =0 , padx = 5 ,pady =5)

        self.lbl_end = tk.Label(self, text="To: ")
        self.lbl_end.grid(row=0, column=2)

        self.lbl_bedsNo = tk.Label(self, text="No. of beds: ")
        self.lbl_bedsNo.grid(row=2, column=0)


        #######entries
        self.entry_start = tk.Entry(self)
        self.entry_start.grid(row = 0 ,column = 1)

        self.entry_end = tk.Entry(self)
        self.entry_end.grid(row=0, column=3)

        self.entry_bedsNo = tk.Entry(self,state='disabled')
        self.entry_bedsNo.grid(row=2, column=1)


        #####radiobuttons
        self.rbtn_single = ttk.Radiobutton(self, text="Single")
        self.rbtn_single.grid(row=1, column=0)

        self.rbtn_double = ttk.Radiobutton(self, text="Double")
        self.rbtn_double.grid(row=1, column=1)

        self.rbValue_type = tk.StringVar()
        self.rbtn_single.config(variable=self.rbValue_type, value="Single",command = lambda :self.rBtn(controller,self.rbValue_type))
        self.rbtn_double.config(variable=self.rbValue_type, value="Double",command = lambda :self.rBtn(controller,self.rbValue_type))

        ##
        self.rbtn_sweet = ttk.Radiobutton(self, text="Sweet")
        self.rbtn_sweet.grid(row=3, column=0)

        self.rbtn_ordinary = ttk.Radiobutton(self, text="Ordinary")
        self.rbtn_ordinary.grid(row=3, column=1)

        self.rbValue_size = tk.StringVar()
        self.rbtn_sweet.config(variable=self.rbValue_size, value="Sweet")
        self.rbtn_ordinary.config(variable=self.rbValue_size, value="Ordinary")
        ##
        self.rbtn_oversea = ttk.Radiobutton(self, text="Oversea")
        self.rbtn_oversea.grid(row=4, column=0)

        self.rbtn_nonover = ttk.Radiobutton(self, text="Non-Oversea")
        self.rbtn_nonover.grid(row=4, column=1)

        self.rbValue_location = tk.StringVar()
        self.rbtn_oversea.config(variable=self.rbValue_location, value="Oversea")
        self.rbtn_nonover.config(variable=self.rbValue_location, value="Non-Oversea")

        #####buttons
        self.btn_next = tk.Button(self, text="Next", command=lambda: self.click_next(controller))
        self.btn_next.grid(row=5, column=5,padx=5)

        self.btn_back = tk.Button(self, text="Back", command=lambda: self.click_back(controller))
        self.btn_back.grid(row=5, column=4,padx=5)



    def clear(self):
        self.entry_bedsNo.delete('0','end')
        self.entry_end.delete('0','end')
        self.entry_start.delete('0','end')



    def rBtn(self,controller,rbt_Value):
        if (rbt_Value.get() == "Double"):
            self.entry_bedsNo.configure(state=tk.NORMAL)
        else:
            self.entry_bedsNo.configure(state=tk.DISABLED)


    def set_client(self,c):
        self.client = c

    def click_back(self,controller):
        controller.show_page(personalData)

    def click_next(self,controller):
        start = self.entry_start.get()
        end = self.entry_end.get()
        noBeds = self.entry_bedsNo.get()
        if(noBeds==""):
            noBeds="1"
        roomSize = self.rbValue_size.get()
        roomType = self.rbValue_type.get()
        roomLocation = self.rbValue_location.get()
        if (roomType == "Double" and int(noBeds) < 2):
            tkinter.messagebox.showinfo("Wrong Data", "Double rooms must have 2 beds or more!")
        elif(start !="" and end !="" and noBeds !="" and roomSize!="" and roomType!="" and roomLocation!="" and not(roomType == "Double" and int(noBeds) < 2)):
            reservation = Reservation()
            reservation.set_client(self.client)
            reservation.set_bedsNo(noBeds)
            reservation.set_endDate(end)
            reservation.set_roomLocation(roomLocation)
            reservation.set_roomSize(roomSize)
            reservation.set_roomType(roomType)
            reservation.set_startDate(start)

            controller.set_reservation_inPackagePage(reservation)
            controller.show_page(packagePage)
        else:
            tkinter.messagebox.showinfo("Data Missing" , "Please fill in all data required")


class packagePage(tk.Frame):

    reservation = Reservation()
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)

        self.lbl = tk.Label(self, text="Select Packages")
        self.lbl.grid(row=0, column=1, columnspan=2)

        ####checkboxes
        self.var_meals = tk.IntVar()
        self.check_allMeals = tk.Checkbutton(self, text="Breakfast , Lunch & Dinner", variable=self.var_meals)
        self.check_allMeals.grid(row=1, column=0, padx=5, pady=5)

        self.var_roomservice = tk.IntVar()
        self.check_roomService = tk.Checkbutton(self, text="Room Service", variable=self.var_roomservice)
        self.check_roomService.grid(row=1, column=2, padx=5, pady=5)

        self.var_minibar = tk.IntVar()
        self.check_miniBar = tk.Checkbutton(self, text="Mini-bar", variable=self.var_minibar)
        self.check_miniBar.grid(row=3, column=1, padx=5, pady=5)

        ####buttons
        self.btn_next = tk.Button(self, text="Next", command=lambda: self.click_next(controller))
        self.btn_next.grid(row=4, column=5, padx=5)

        self.btn_back = tk.Button(self, text="Back", command=lambda: self.click_back(controller))
        self.btn_back.grid(row=4, column=4, padx=5)



    def click_back(self,controller):
        controller.show_page(bookingData)


    def click_next(self,controller):
        package = Package()
        price = 0
        flag = 0
        name = ""

        if (self.var_meals.get() == 1):
            flag = 1
            name += "Breakfast , Lunch & Dinner\n"
            price += 50

        if (self.var_minibar.get() == 1):
            flag = 1
            name += "Minibar\n"
            price += 30

        if (self.var_roomservice.get() == 1):
            flag = 1
            name += "Room Service\n"
            price += 10

        if (flag == 1):
            package.set_packageName(name)
            package.set_packagePrice(price)

        else:
            name = "None"
            price = 0
            package.set_packageName(name)
            package.set_packagePrice(price)



        self.reservation.set_package(package)
        controller.set_reservation_inPricePage(self.reservation)
        #####calc price
        price +=self.calc_price()
        duration = self.calc_duration(self.reservation.get_startDate(), self.reservation.get_endDate())
        price=price*duration
        controller.change_pricePage_label(str(price))
        controller.show_page(pricePage)




        ####

        controller.show_page(pricePage)


    def set_reservation(self, reserv):
        self.reservation = reserv


    def calc_duration(self,start,end):
        Sindex = start.index('/')
        startDay= int(start[0:Sindex])
        startMonth = int(start[Sindex+1:])

        Eindex = end.index('/')
        endDay = int(end[0:Eindex])
        endMonth = int(end[Eindex+1:])
        period=0

        if(startMonth == endMonth):
            period = endDay- startDay
        elif(startMonth!= endMonth):
            period=30-startDay+endDay+((endMonth-(startMonth+1))*30)

        return period




    def calc_price(self):
        roomtype = self.reservation.get_roomType()
        roomsize = self.reservation.get_roomSize()
        bedsno = int(self.reservation.get_bedsNo())
        location = self.reservation.get_roomLocation()

        start = self.reservation.get_startDate()
        end = self.reservation.get_endDate()

        orgprice=50
        if (roomtype =="Single"):
            orgprice+=0
        elif (roomtype=="Double"):
            orgprice+=20

        if (roomsize == "Sweet"):
            orgprice+=100
        elif(roomsize=="Ordinary"):
            orgprice+=0

        if(bedsno > 2):
            orgprice+=((bedsno-2)*40)

        return orgprice


class pricePage(tk.Frame):
    reservation = Reservation()

    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        self.lbl_price = tk.Label(self, text= "")
        self.lbl_price.grid(row = 1 , column = 2 , padx =10 , pady = 10)

        self.btn_cash=tk.Button(self,text = "Cash" , command = lambda :self.click(controller))
        self.btn_cash.grid(row = 3 , column =2  , padx=5 , pady=5)

        self.btn_credit = tk.Button(self, text="Credit", command=lambda: self.click(controller))
        self.btn_credit.grid(row=3, column=3, padx=5, pady=5)

        self.btn_back = tk.Button(self, text="Back", command=lambda: self.click_back(controller))
        self.btn_back.grid(row=3, column=1, padx=5, pady=5)


    def click(self,controller):
        DB_clients.append(self.reservation.get_client())
        DB_reservations.append(self.reservation)
        controller.show_page(mainPage)
        controller.clearAll()
    def click_back(self,controller):
        controller.show_page(packagePage)

    def set_reservation(self, reserv):
        self.reservation = reserv

    def change_labelPrice(self,txt):
        self.lbl_price.configure(text=txt)

class viewPage(tk.Frame):
    def __init__(self,parent,controller):
        tk.Frame.__init__(self,parent)

        self.tree = ttk.Treeview(self)

        ###columns
        self.tree["columns"] =("one" ,"two","three","four","five","six","seven")
        self.tree.column("#0" , width =50 , minwidth = 5 , stretch = tk.NO)
        self.tree.column("one", width=200, minwidth=20, stretch=tk.NO)
        self.tree.column("two", width=100, minwidth=10, stretch=tk.NO)
        self.tree.column("three", width=100, minwidth=10, stretch=tk.NO)
        self.tree.column("four", width=100, minwidth=20, stretch=tk.NO)
        self.tree.column("five", width=100, minwidth=20, stretch=tk.NO)
        self.tree.column("six", width=100, minwidth=20, stretch=tk.NO)
        self.tree.column("seven", width=100, minwidth=20, stretch=tk.NO)

        #####
        ###headings
        self.tree.heading("#0", text="ID", anchor=tk.W)
        self.tree.heading("one", text="Client Name", anchor=tk.W)
        self.tree.heading("two", text="Start Date", anchor=tk.W)
        self.tree.heading("three", text="End Date", anchor=tk.W)
        self.tree.heading("four", text="Room Size", anchor=tk.W)
        self.tree.heading("five", text="Room Type", anchor=tk.W)
        self.tree.heading("six", text="Beds Number", anchor=tk.W)
        self.tree.heading("seven", text="Room Location", anchor=tk.W)
        self.tree.grid(row =0 ,column =0, sticky = "nsew")

        self.btn_back = tk.Button(self, text="Back", command=lambda: self.click_back(controller))
        self.btn_back.grid(row=4, column=4, padx=5)

    def click_back(self, controller):
        controller.show_page(mainPage)

    def fill_tree(self):
        #####
        for j in self.tree.get_children():
            self.tree.delete(j)

        i = 1
        for res in DB_reservations:
            client = res.get_client()
            name = client.get_name()
            sd = res.get_startDate()
            ed = res.get_endDate()
            rs = res.get_roomSize()
            rt = res.get_roomType()
            nb = res.get_bedsNo()
            l = res.get_roomLocation()

            self.tree.insert("", i,text = str(i), values=(name, sd, ed, rs, rt, nb, l))
            i += 1
        ########

class delete_checkoutPage(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)

        self.tree = ttk.Treeview(self)

        ###columns
        self.tree["columns"] = ("one", "two", "three", "four", "five", "six", "seven")
        self.tree.column("#0", width=50, minwidth=5, stretch=tk.NO)
        self.tree.column("one", width=200, minwidth=20, stretch=tk.NO)
        self.tree.column("two", width=100, minwidth=10, stretch=tk.NO)
        self.tree.column("three", width=100, minwidth=10, stretch=tk.NO)
        self.tree.column("four", width=100, minwidth=20, stretch=tk.NO)
        self.tree.column("five", width=100, minwidth=20, stretch=tk.NO)
        self.tree.column("six", width=100, minwidth=20, stretch=tk.NO)
        self.tree.column("seven", width=100, minwidth=20, stretch=tk.NO)

        #####
        ###headings
        self.tree.heading("#0", text="ID", anchor=tk.W)
        self.tree.heading("one", text="Client Name", anchor=tk.W)
        self.tree.heading("two", text="Start Date", anchor=tk.W)
        self.tree.heading("three", text="End Date", anchor=tk.W)
        self.tree.heading("four", text="Room Size", anchor=tk.W)
        self.tree.heading("five", text="Room Type", anchor=tk.W)
        self.tree.heading("six", text="Beds Number", anchor=tk.W)
        self.tree.heading("seven", text="Room Location", anchor=tk.W)
        self.tree.grid(row =0 ,column =0, sticky = "nsew")

        self.btn_back = tk.Button(self, text="Back", command=lambda: self.click_back(controller))
        self.btn_back.grid(row=4, column=3, padx=5)

        self.btn_delete = tk.Button(self, text="Delete/Checkout", command=lambda: self.click_delete(controller))
        self.btn_delete.grid(row=4, column=4, padx=5)

        self.entry = tk.Entry(self)
        self.entry.grid(row = 4 ,column =7 , padx=5)

        self.lbl = tk.Label(self,text = "Enter ID of Reservation")
        self.lbl.grid(row =4 ,column =6 ,padx=5)


    def click_back(self, controller):
        self.entry.delete(0,"end")
        controller.show_page(mainPage)

    def fill_tree(self):
        #####
        for j in self.tree.get_children():
            self.tree.delete(j)

        i = 1
        for res in DB_reservations:
            client = res.get_client()
            name = client.get_name()
            sd = res.get_startDate()
            ed = res.get_endDate()
            rs = res.get_roomSize()
            rt = res.get_roomType()
            nb = res.get_bedsNo()
            l = res.get_roomLocation()

            self.tree.insert("", i, text=str(i), values=(name, sd, ed, rs, rt, nb, l))
            i += 1
        ########

    def click_delete(self,controller):
        id = int(self.entry.get())
        if (id >0):
            del DB_reservations[id-1]
            controller.fill_data_in_tree()
            self.entry.delete(0,"end")






####main
app = controller()
app.title("Hotel Reservation System")
app.mainloop()






