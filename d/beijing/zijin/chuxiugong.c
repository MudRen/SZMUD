//Cracked by Roath
// Room: /d/beijing/zijincheng/chuxiugong.c

inherit ROOM;

void create()
{
	set("short", "���㹬");
	set("long", @LONG
����ԭ����˳����谮�����Ӷ�������ס�ĵط�����������������
˳��Ҳһֱ�����������þͼݱ��ˡ��������˾�ס��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"xianfugong",
  "south" : __DIR__"tihedian",
  "north" : __DIR__"lijingxuan",
  "east" : __DIR__"tongdao3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
