// Code of ShenZhou
//Kane
//maco moveed to hangzhou 1999/12/28 

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǿƹ����֮���һ�����ң�ֻ�������߼������������
һ��������һֻ�����䣬��ȴ˿�����ֵþִ٣�����Ҳʮ�����£�
�Ų���һ��ùζ��
LONG
	);

        set("no_fight", "1");
	set("resource/water", 1);
	set("exits", ([
                "out" : __DIR__"jiudian",
        ]));

	set("cost", 2);
/*	
	set("item_desc", ([
	"skulls" : "����һ�ѹ��Ÿ���ͷ�ǣ���Ϊ���������㣬�²�������в��������ϲ�һ��\n",
	]));
*/

	set("objects", ([
		"/kungfu/class/taohua/lingfeng" : 1,
	]));

	setup();
	replace_program(ROOM);
}
