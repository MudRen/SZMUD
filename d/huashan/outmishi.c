// Code of ShenZhou
// ��ɽС��
// qfy 30/8/1997

inherit ROOM;

void create()
{
	set("short", "��ɽС��");
	set("long", @LONG
���ǻ�ɽ��ɽ��һ��С�����˼�����������Ұ�������������飬Ҫ��
�Ǵ������������˭Ҳ���ᵽ��������
LONG
	);

	set("outdoors", "huashan");

	set("exits", ([ /* sizeof() == 1 */
	"northup":__DIR__"xiaolu2",
]));

	set("cost", 2);
	setup();
	replace_program(ROOM);
}
 
