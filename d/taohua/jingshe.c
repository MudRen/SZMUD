// Code of ShenZhou
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������ȫ������ɫ�����ɣ������������٣�ʹ��һ��֮�����ж������⡣
��Χ�����滨��ݣ���֮������ס������俴�ƴֲڣ���ϸ��֮�£�ȴ�������Ᾱ��
���ܾ����Ȼ��ɣ���ͬ��Ȼ���ɵ�һ�㣬�������ɶ��칤����һƬ�������졣����
����С��ͨ���һ����
LONG
	);
	 set("exits", ([
               	"west" : __DIR__"taolin",
                "south" : __DIR__"bibochi",
                "enter" : __DIR__"shuilong",
        ]));

         set("objects", ([
                 "/d/taohua/npc/shagu" : 1,
        ]));

	set("outdoors", "taohua");
	set("cost", 2);

	setup();
        "/clone/board/taohua_b"->foo();
}

int valid_leave(object me, string dir)
{

        if( (me->query("family/master_name") != "��Ӣ")
        && (me->query("family/master_name") != "��ҩʦ")
        && (!me->query_temp("shagu_pass"))
	&& (dir == "enter")
        && present("sha gu", this_object()) )
	return notify_fail("\nɵ��ɵЦ�˼������쿪˫��һ����˵����Ҫ��ȥ��������һ����ɣ�\n�����˶������ң������ˣ�\n");
        return ::valid_leave(me, dir);
}
