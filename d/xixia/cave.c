// Code of ShenZhou
//Kane

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����ɳĮ����Ȼ�γɵ�һ��ʯ�������й��߻谵����ȴʮ�ָ��
�������߼��ѵ��ݣ��ƺ��ǹ���˯��֮�ã��������������з·�����
��ˮ��������һ�Ƿ���������ͷ��(skulls)��
LONG
	);

      set("resource/water", 1);
	set("exits", ([
                "out" : __DIR__"desert2",
        ]));

	set("cost", 2);
	set("item_desc", ([
	"skulls" : "����һ�ѹ��Ÿ���ͷ�ǣ���Ϊ���������㣬�²�������в��������ϲ�һ��\n",
	]));


	set("objects", ([
		"/kungfu/class/taohua/chaofeng" : 1,
		"/kungfu/class/taohua/xuanfeng" : 1,
	]));

	setup();
	replace_program(ROOM);
}
