void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
                int addvalue;
                object ob;
        string strID;
        string msgvalue;
        string outmsg;
                string strRes;


        if( !arg || sscanf(arg, "%s %s %s", strID, msgvalue, strRes)!=3 )
        {
                write("格式错误\n");
                return 1;
        }

        addvalue = atoi(msgvalue);
        
        ob = find_player(strID);

        ob->add("shenzhou/pts", addvalue);
                
                log_file("/awards/gxadd",this_player()->query("name") + " 给予"+ ob->query("name") + " (" + ob->query("id") + ") " + addvalue + "点, 因为" + strRes + " 在 " +ctime(time())+"\n"); 
        
                write("增加完毕\n");

        return 1;
}

