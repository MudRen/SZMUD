// Code of ShenZhou
// Room: taogu.c �ҹ�
// qfy July 25, 1996.

inherit ROOM;

void reset();
int valid_leave(object, string);

void create()
{
    set("short", "�ҹ�");
    set("long", @LONG
С����ͷ����һɽ�ȣ��������У��ļ��紺��ɽ���ڳ�����һ��
Ƭ���֣�����һ�������ڡ��ź����Ǵ˴���Ȼ����֮������������
��֮�У�ԭ���м����϶���Ϊһ��֥���̶���С�¸������۲��ݡ���
��������һ��С����
LONG
    );

    set("exits", ([
	"south" : __DIR__"xiaojing1",
	"northeast" : __DIR__"xiaojing2",
    ]));

    set("objects", ([
        __DIR__"npc/tao6" : 1,
	__DIR__"npc/tao5" : 1,
	__DIR__"npc/tao4" : 1,
	__DIR__"npc/tao3" : 1,
        __DIR__"npc/tao2" : 1,
        __DIR__"npc/tao1" : 1,
    ]));

    set("no_clean_up", 0);

	set("cost", 1);
    setup();
    //replace_program(ROOM);
}

void init()
{
	add_action("do_hit", "hit");
}

int do_hit(string arg)
{
	write("���˲������£����ǹ����������ս�ɣ�\n");
	return 1;
}

int valid_leave(object me, string dir)
{
    if ( me->query("family/master_id") != "feng qingyang" && dir == "northeast" ) {

	if ( !me->query_temp("win/tao1") && present("tao genxian", environment(me)) )
	   	return notify_fail("�Ҹ�������һ�������㻹û���ҽ����أ�\n");

	if ( !me->query_temp("win/tao2") && present("tao ganxian", environment(me)) )
		return notify_fail("�Ҹ��ɲ�����·�����㻹û���ұȻ�Ӵ��\n");

	if ( !me->query_temp("win/tao3") && present("tao zhixian", environment(me)) )
		return notify_fail("��֦����������˵������ô���Ҹ�����ѽ��\n");

	if ( !me->query_temp("win/tao4") && present("tao yexian", environment(me)) )
                return notify_fail("��Ҷ��˫��һ̯˵�����뵽�Ƕ�ȥѽ����\n");

	if ( !me->query_temp("win/tao5") && present("tao huaxian", environment(me)) )
        	return notify_fail("�һ���Ц������˵�����ֵ���������������˰ɣ�\n");

	if ( !me->query_temp("win/tao6") && present("tao shixian", environment(me)) )
        	return notify_fail("��ʵ��ǿ׳��ɫ˵����ù��ұ�����ȥ����ǰ����\n");

    }		

    return ::valid_leave(me, dir);
}
