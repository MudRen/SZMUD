
// Room��/u/xuebi/workroom.c

#include <ansi.h>
#include <room.h> 
inherit ROOM;

void create()
{
        set("short", HIW "��ѩС��" NOR);
        set("long", @LONG
����һ�������Լһ��ƽ���İ칫�ң�һ��������һ�����º͵��ŵĸо���
������һ�ſ��Ĵ���ɫ��Ƥɳ���������ŵ���һ������ǽ�Ϲ��ż����ϼ���
�ĳ��󻭵İ칫������ǽ�Ϲ��ż����ϼ����ĳ��󻭡�
LONG
        );
        set("no_fight",1);
        set("exits", ([ /* sizeof() == 3 */
                  "kd"  : "d/city/kedian",
        ]));
        setup();
}
