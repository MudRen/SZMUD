// Code of ShenZhou
// Room: /d/xiangyang/diluqiao.c

inherit ROOM;

void create()
{
	set("short", "��¬��");
	set("long", @LONG
����Сľ�����ɸ����������ź�ʱ�������˵�����ԾϪ��������������С��
ҡҡ�λΣ�����Σ�գ���ʵ�����ȹ̡���Χ��ɽ��ˮ����ľ���ף�����̴Ϫ��ˮ
���ȣ��羰������
LONG
	);
        set("coordinates", ([ "x" : -11, "y" : 0 ]) );
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"tanxi",
  "westdown" : __DIR__"wotieniu",
]));

	setup();
	replace_program(ROOM);
}
