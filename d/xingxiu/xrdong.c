// Code of ShenZhou
// Ryu, 5/10/97

inherit ROOM;

void create()
{
	set("short", "���˶�");
	set("long", @LONG
·����һ�����;��յ�ʯ��(feng)���䣬��һʯ���������ʮ�ߡ�
��������ι�����������ӡ��������ɻ��У��������С����ٶ�����
��������֡��ݴ�������ǰ��һλ������ԭ�ĵ��ˣ������շ�����
�˶���
LONG
	);
	set("exits", ([
                "south" : __DIR__"ertai",
        ]));
	set("cost", 2);
	set("outdoors", "tianshan");

	setup();
}
void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" )
                return 0;
        if( arg=="feng")
        {
	if (me->query_skill("dodge") < 30){
                    write("����ͼ����ʯ�壬�������������ݣ�ֻ�����ա�\n");
                return 1;
                }
                else {
                    write("��һ����˳��ʯ������������\n");
                    message("vision",
                             me->name() + "һ����˳��ʯ��������ȥ��\n",
                             environment(me), ({me}) );
                    me->move(__DIR__"xrdong1");
                    message("vision",
                             me->name() + "����������������\n",
                             environment(me), ({me}) );
                return 1;
         }
     }
}

