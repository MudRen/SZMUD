//Cracked by Roath
// Room: /d/beijing/east/yumadamen.c

inherit ROOM;

void create()
{
	set("short", "����Ȧ����");
	set("long", @LONG
�����Ͻ���������Ȧ�Ĵ��ţ�ƽ���ǲ����ģ�ֻ�лʵۼ�
�ٲŻ�󿪡�ƽ���ɰ���ƥ�����ϵ��˶��Ǵ�ƫ�Ž�����Ѱ��
�����ǲ��ܿ����ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"qianyuan",
  "southwest" : "/d/beijing/zijincheng/donghuamen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
