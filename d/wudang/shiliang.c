// Code of ShenZhou
// shiliang.c �䵱ʯ��
// by Fang 8/19/96

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
	������ɽ���У���һ��ʯ����Ϫ�����������ǾŶɽ�������������֮ˮ��
�ڴ˽��㣬��ɫ���ѡ������������С�Ե꣬�������ˣ����СסЪЪ����������
�Ͼ��Ƕ��͵�ʮ�����ˡ�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southup" : __DIR__"shibapan",
		"northup" : __DIR__"taizipo",
	]));

	set("cost", 2);
	setup();
	replace_program(ROOM);
}

