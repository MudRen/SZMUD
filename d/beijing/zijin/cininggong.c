//Cracked by Roath
// Room: /d/beijing/zijincheng/cininggong.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǻ�̫���ס�ĵط����������ź��ĵ�̺��������һ����
����ƽʱ��δ��̫�����٣��ǲ���������ġ��Ա���һ���ǳ�����
�Ļ�԰��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"shoukanggong",
  "north" : __DIR__"dafotang",
  "south" : __DIR__"ciningmen",
  "east" : __DIR__"longzongmen",
]));
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
