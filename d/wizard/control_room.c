#include <ansi.h>

inherit ROOM;

void create()
{
    set( "short", HIB"������"NOR );
    set( "long", HIW"���������ݿ������ĵ����ң�����������ĸ�����ʦ�������������\n"+
                    "����ʦ�����ԱҪ��û������Ŀ�����ʦҲ������������Լ������Ĺ�\n"+
                    "�����Է�����ȵ���Ҫ��\n"NOR );
    set( "no_sleep_room", 1 );
    set( "non_fight", 1 );
    
    set( "exits", ([
                "east" : __DIR__"meeting_room",
                ]));
    
   call_other( "/clone/board/control_room", "???" ); 
}


            