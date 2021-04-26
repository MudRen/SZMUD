// Room: /d/wizard/wizard_room.c
// huaishi Aug 14, 2001
// ���ݹ��׶� SET BY SCATTER

#include <ansi.h>
inherit ROOM;


void create()
{
                seteuid(getuid());


        set("short", HIY"�ƽ���"+NOR);
        set("long", @LONG
������һ���ƽ�ĵ��ã�ʮ����ΰ������������˸��⡣ǰ�����߳����
�������ܡ��ʻ�г����ĸ�һ�˱���ס���������ӡ��������м���ž޴�ĺ�ľ
Բ�����������ҵط���һ���������ͼֽ���ĸ壬����������עĿ����һ������
���С���ӣ�������д���������塸��ѫ�᡹(ce)��

���¹��� (BETA V 1.0)
checkgx <ID> (���Բ鿴��ҵ� ���� ���׶�)
gxadd <ID> <AMOUNT> because <ԭ��> (��ĳ����Ҽ� ���� ���׶�)
gxmin <ID> <AMOUNT> because <ԭ��> (��ĳ����Ҽ� ���� ���׶�)

LONG
        );
        set("exits", ([ 
                  "up"  : "/d/wizard/meeting_room",
                  "west"  : "/d/death/noteroom",
                  "cl"  : "/d/forest/clzoulang2",                  
                  "down"  : "/d/wizard/guest_room",                  
                  
]));
        
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("cost", 0);
        setup();
        call_other("/clone/board/wiz_b", "???");
}

void init()
{
        object me = this_player();

                add_action("do_checkgx", "checkgx");
                add_action("do_gxadd", "gxadd");
                add_action("do_gxmin", "gxmin");

        if (wizhood(me) == "(player)")
                me->move("/d/death/death.c");
}

int do_checkgx(string arg)
{
        object ob;
        int chkvalue;
        string outmsg;
        
        ob = find_player(arg);
        if(!ob->query("shenzhou/pts"))
        {
                write("������û�С����� ���׶ȣ�\n");
                return 1;
        }

        chkvalue = ob->query("shenzhou/pts");
        outmsg = ob->name(1) + " �� ���� ���׶�Ϊ " + chkvalue + " �㣮\n";
        write(outmsg);
        return 1;
}

int do_gxadd(string arg)
{
        object ob;
        int addvalue;
        string strID;
        string msgvalue;
        string outmsg;
                string strRes;


        if( !arg || sscanf(arg, "%s %s because %s", strID, msgvalue, strRes)!=3 )
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


int do_gxmin(string arg)
{
        object ob;
        int addvalue;
        string strID;
        string msgvalue;
        string outmsg;
                string strRes;


        if( !arg || sscanf(arg, "%s %s because %s", strID, msgvalue, strRes)!=3 )
        {
                write("��ʽ����\n");
                return 1;
        }

        addvalue = atoi(msgvalue);
        
        ob = find_player(strID);

        ob->add("shenzhou/pts", -addvalue);

                log_file("/awards/gxmin",this_player()->query("name") + " ����"+ ob->query("name") + " (" + ob->query("id") + ") " + addvalue + "��, ��Ϊ" + strRes + " �� " +ctime(time())+"\n"); 

        write("��ȥ���\n");

        return 1;
}

