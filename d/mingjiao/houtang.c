// Code of ShenZhou
// Room: /d/mingjiao/houtang.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�۰׵��ı��������ż�����īɽˮ����ǽ��һ��ľ�ʴ��������ϴ�֮
��Ľ���������һ�����¾գ��䲻��������������ɽ������Ҳ�ѽ����˹�
�٣����ż����Ͳ�ס��į�Ļ��꣬������������١����м�ڷ��ź�ľ��
��������֪Ϊ˭׼����һ���Ʋˣ���ɢ��������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"zoulang",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
