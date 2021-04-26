// Code of ShenZhou
// Room: /d/xiangyang/xushuzai.c

inherit ROOM;

void create()
{
	set("short", "����լ");
	set("long", @LONG
�ഫ����ʱ�����������˱���ʧ��ɱ�ˣ����������ӣ���������������Ԣ
춴ˡ������ݹ�ǰ����Ժ��������������ľ�Բԣ�����ˮ����ǽ���������Ե�
ʮ�����ġ���Ժ����һ������(xiang)��ǰ��һ��ޱ�(bei)��
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -12, "y" : -2 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"qilidian",
]));
	set("item_desc", ([
		"xiang" : "̧ͷ��ʱ���������������ۣ��������ģ���ò������񳡣\n",
		"bei" : "���Ͽ��š����������Ρ����֡�\n",
	]));
	setup();
	replace_program(ROOM);
}
