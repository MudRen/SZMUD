//xuanpiao.c
//create by rama@sz

inherit ITEM;

#include <ansi.h>

void get_id( string arg);
int check_legal_id(string id);
void confirm_xuan(string yn);
void get_menpai(string arg);

string *opt1 = ({ 
"25��������",
"30��������",
"35��������",
"40��������",
"45��������",
"55��������",
"65��������",
"99��������",
"�������(��������,���мȿ�)",
"���µ�һ����",
});

string *msg=({"","","","","","","","","","",""});
string temp="";
int i=0;

void create()
{
        set_name("������ѡƱ", ({ "xuan piao","piao" }));
        set_weight(10);
        set("long","����һ�ű�����ѡƱ��
����д�ţ�
        25�������飺
        30�������飺
        35�������飺
        40�������飺
        45�������飺
        55�������飺
        65�������飺
        99�������飺
        �������(��������,���мȿ�)��
        ���µ�һ���ɣ�
�������xuan����дѡƱ��\n");
        set("unit", "��");
        set("value", 0);
        setup();
              
}

void init()
{
        add_action("do_xuan","xuan");
}

int do_xuan()
{
        object ob = this_object();
        if( ob->query("done",1))
                return notify_fail("ѡƱ���ܸ��ġ�\n");
        if( i>=10)
        {
                write("��ѡ����ô��(Yes/No)\n");
                input_to( (:confirm_xuan :) );
                return 1;
        }

        write("�����"+opt1[i]+"˭��Ӯ��\n");
        input_to( (: get_id :));
        return 1;
        
}

void get_id( string arg)
{
        
        arg = lower_case(arg);
        if( !check_legal_id(arg)) 
        {
                input_to("get_id");
                return;
        }
        msg[i]=arg;
        temp += opt1[i]+"�� "+msg[i]+"\n"; 
        i=i+1;
        do_xuan();
}       


int check_legal_id(string id)
{
    int len;
    len = strlen(id);
    
     if( (strlen(id) < 3) || (strlen(id) > 60 )  ) {
        write("����ID��ʽ��������ã���������\n");
        return 0;
    }
/*    while(len--)
        if( id[len]<'a' || id[len]>'z' || id[len]!="," ) {
            write("����ID��ʽ��������ã���������\n");
            return 0;
        }
*/
    return 1;
}

void confirm_xuan(string yn)
{
        object ob=this_object();
        int n;
        if( yn[0]!='y' && yn[0]!='Y' ) 
        {
                write("�Ǻúÿ���һ�°ɡ�\n");
				temp = "";
                i=0;
                return;
        }
		temp += "\n����ѡƱ������"+ctime(time())[0..15]+"��д�ġ�\n";
        ob->set("done_time",time());
        ob->set("long",temp);
        ob->set("done",1);
        ob->set_name(this_player()->query("name")+"�ı���ѡƱ",({this_player()->query("id")+"'s piao"}) );
        write("������������ѡƱ��\n");
        return;         
}



