#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "��԰");
		  set("long",@long
����һ����԰��԰�е��ʻ���ŭ���ţ���������·�������������ġ�
�������ٷ��������ǳ��ȣ���������ƽ����ʯ��·��
long);
		 set("exits",([
"north" : __DIR__"shilu1",
"south" : __DIR__"lang2",
"west" : __DIR__"qinshi1",
]));
set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
