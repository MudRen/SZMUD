// Code of Shenzhou
// Jay 8/9/96

//#include <login.h>

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������һ�ţ�Ψһ��һ�߹����Ǵ�����һ����������Ŀ׶���
������ġ��ı������͵ط������⣬ԭ������ǽ�ھ��Ǹ���������
LONG
        );

//        set_light(0);
        set("sleep_room", "1");
        set("no_fight", "1");

        set("exits", ([
		"out" : __DIR__"mzgate1",
	]));
        set("item_desc", ([
                "dianzi" : "һ֧����Ĳݵ��ӣ�������ȥ�����������ǿ����壬\n",
        ]));

	set("objects", ([
                __DIR__"obj/tiechuang" : 1,
	]));
        set("valid_startroom",1);

        set("no_clean_up", 0);

	set("cost", 2);
	setup();
}
/*
int valid_leave(object me, string dir)
{
    object heibai;

    if ( (dir=="out") && present("liaokao",me))
		return notify_fail("�㱻����������Ŷ������á�\n");
    if( dir=="out" && me->query("max_neili")==0)
	return notify_fail("���������ѳ�����ɢ��֮��ȫ���������겻��ȥ��\n");
    if(dir == "out") {
    if (heibai=(present("heibai zi",environment(me))))
	destruct(heibai);
	me->set_temp("tieslept",0);
    }
        return ::valid_leave(me, dir);
}
*/
