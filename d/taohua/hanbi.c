// Code of ShenZhou
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "���̷�");
	set("long", @LONG
���̷�ʵ������һ��˶�������̫��ʯ�壬���������࣬��Ϊ�ر��ʺ���̦������
ͨ����̣��ʶ����������̡����ݴ�˵�����ǻ�ʯ�������е���Ʒ����������������
�µ����Ʒ��ʨ�ӷ����й�֮���޲�����ԭַ�������ݣ����ҩʦ���˷���ԭ�����ݣ�
��ҩʦ�ŷ�ټ����������֮�����һ�����ʹ���˲�����Ƨ������֮�С�
LONG
	);
	 set("exits", ([
                "south" : __DIR__"songlin3",
                "northeast" : __DIR__"bibochi",
        ]));

/*
        set("objects", ([
                "/d/taohua/npc/shagu" : 1,
        ]));
*/
	set("cost", 2);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}

/*
int valid_leave(object me, string dir)
{

        if( (me->query("family/master_name") != "��Ӣ")
        && (me->query("family/master_name") != "��ҩʦ")
        && (!me->query_temp("shagu_pass"))
        && present("sha gu", this_object()) )
        return notify_fail("\nɵ��ɵЦ�˼������쿪˫��һ����˵����Ҫ��ȥ��������һ����ɣ������˶������ң������ˣ�\n");

        return ::valid_leave(me, dir);
}
*/
