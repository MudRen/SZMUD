// Room Of Mxj
// have a good day
// Code of ShenZhou
inherit ROOM;
#include <ansi.h>  
void create()
{
        set("short","������");
        set("long","������һЩ���������Խ��������ң�ר���ṩ��ͬ������������
    ���輫��򵥣�������һЩ���Σ�һЩ�����ڴ������ɡ�ż�����˽���Ҳ��
    С�������ſ�д��һ����ʾ������Բο�"HIG"help guaji"NOR" ,"HIG"help scheme"NOR" ��
    "HIG"help trigger"NOR"��ʹ�����߻����ˡ�\n");
        
        
        
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
