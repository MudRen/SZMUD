// Code of ShenZhou
// Room: /u/qfy/quanzhou/nantai.c

inherit ROOM;

void create()
{
	set("short", "��̨��");
	set("long", @LONG
������ǧ���Ϳ��项��������Դɽ����ߴ���һƬ���ʵľ�ʯ��Ȼ������
ǰ���������ͱڣ�����ʮ���վ�����ʯ���Կ��š�����̨���Ĵ��֡���̨��
�С����Ǹ󡹣���Ϊɽ�Ƹߣ����ﳣ����������Ϊ�ƺ�����ɽ�����ӣ�����
���С�
LONG
	);

	set("outdoors", "quanzhou");

	set("exits", ([ /* sizeof() == 2 */
		"eastdown" : __DIR__"qingyuan",
		"westdown" : __DIR__"laojun",
	]));
        set("fjing", 1);

	set("no_clean_up", 0);

	set("cost", 3);
	setup();
	replace_program(ROOM);
}
