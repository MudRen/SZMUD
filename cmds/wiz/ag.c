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
                write("��ʽ����\n");
                return 1;
        }

        addvalue = atoi(msgvalue);
        
        ob = find_player(strID);

        ob->add("shenzhou/pts", addvalue);
                
                log_file("/awards/gxadd",this_player()->query("name") + " ����"+ ob->query("name") + " (" + ob->query("id") + ") " + addvalue + "��, ��Ϊ" + strRes + " �� " +ctime(time())+"\n"); 
        
                write("�������\n");

        return 1;
}

