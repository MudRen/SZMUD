// Code of ShenZhou
// Room: /d/newdali/shilin4.c

inherit ROOM;

void create()
{
	set("short", "��С֥�ƶ�");
	set("long", @LONG
���Ż��۽��붴�ڣ��ػ����У����ã�����һ����Ȼ���ʣ�ʯ���飬ʯ��
ʯ����������͸��������ʤ�����ձ�Ӱ�����´����ң�Ϫ�ƽ�ˮ�������ֺ���ʯ
��δ䣬���Ŀɰ���
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"shilin5",
]));
	set("no_clean_up", 0);
        set("fjing", 1);

	setup();
	replace_program(ROOM);
}
