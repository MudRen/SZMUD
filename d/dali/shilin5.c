// Code of ShenZhou
// Room: /d/newdali/shilin5.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������ܳ�Լʮ�������������Σ������������ܵĴ����С�������һ��
���£��������л�ҫ�������ɰس��֣��Դ����Σ��������£�ɫ��Ҷ�ۣ�����ɽ
������׺��䡣��ˮ���̣���һ����΢���ж����Ľ��У��̵ľ�Ө���̵Ļ�Ծ��
�̵����ˡ�
LONG
	);
	set("cost", 1);
        set("fjing", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"shilin3",
  "west" : __DIR__"shilin2",
  "southdown" : __DIR__"shilin1",
  "enter" : __DIR__"shilin4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
