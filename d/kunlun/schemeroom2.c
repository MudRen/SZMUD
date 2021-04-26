// Code of ShenZhou
#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short",YEL "ɽ��" NOR);
        set("long",
"��������ɽҰ�ȵ�Ϫ���ߣ�ȴ�����˸��ָ����Ļ�����ľ�����췱������Ͽ
�������ʵѹ��ɽ�����˼�����������������ѵط������ģ���Ŀ���ǰ���
һ�����ɣ�shugan����д�ż����֡�\n" 
);

              set("item_desc",([ 
                      "shugan" : "�����Ͽ��ţ���Ҫ��Ӵ�����ʥ�س�ȥ��scheme stop��leave��\n" 
              ])); 

	set("valid_startroom",1);
	set("canScheme", 1);
	set("cost", 0);
	setup();
}

void reset()//make this room no refresh
{
	::reset();
	set("no_clean_up", 1);
}
void init()
{
	object ob = this_player();

	if (!wizardp(ob)) 
	{
		add_action("block_cmd","",1);
		add_action("leave", "leave" );
	}
}

int block_cmd()
{
	string cmd;
	object me = this_player();
	cmd = query_verb();
	if ( cmd == "quit" || cmd == "scheme" || cmd == "leave" || cmd == "chat"
	    || cmd == "l" || cmd == "look" || cmd == "cha" || cmd == "hp" ||
	    cmd == "jifa" )
	    return 0;
	
	if ( me->query( "scheming" ) )
	{
            if (  cmd == "dazuo" || cmd == "tuna" || cmd == "lian" || cmd == "du" || cmd == "yun" )
		    return 0;
    }
    write( "�ú�������.\n" );
	return 1;
}

int leave( string arg )
{
    object me = this_player();
    if ( me->query( "scheming" ) )
        return notify_fail( "����ֹͣ������.\n" );
    me->delete( "scheming" );
    me->move( "/d/city/kedian" );
    return 1;
}
