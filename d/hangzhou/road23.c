// Code of ShenZhou
// ��ʯ���
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "��ʯ���");
    set("long", @LONG
�غ�����Ե������������ֹ��ӣ������۴��αȣ���������������
һƬ̫ƽ���־��󡣽ֶ�����һ������Ժ����Ժ�ﲻʱ�������ʵ�Ц����
LONG);

    set("exits", ([ /* sizeof() == 3 */ 
                   "north" : __DIR__"road22", 
                   "south" : __DIR__"road24", 
                   "east" : __DIR__"shuyuan", 
                 ])
       );
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}