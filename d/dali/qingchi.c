// Code of ShenZhou
// Room: /d/newdali/qingchi.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�������������ܵ��������е��徻����ؽ�����گ��䣬������
�����ڴ���԰�ֹ����İ����£������˲ʡ�������Ϻ��浹Ҳ���˲�
�٣������ļ��紺�������£��ɻ�˯���ޱ���次�
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([
		"east" : __DIR__"shegu",
		]));
	set("no_clean_up", 0);

	setup();
}
