#include <ansi.h>

inherit ROOM;

void create()
{
    set( "short", HIG"��Ժ���"NOR );
    set( "long", "�߽�ͤԺ��ֻ���ٺ�һ��С鿡�������һ����(duilian)�� ���"+
                "\n�ۺ���ֻ���ɻ����������������Զ���塣\n"NOR );
    set( "no_fight", 1 );
    call_other( "/clone/board/hongyan", "???" );
}
