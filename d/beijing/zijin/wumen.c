//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "���� ");
	set("long",  @LONG
�������Ͻ��ǵ����ţ���������ǰ����ʰ��Σ��׳����¥����
¥�����б��������������ӹ����ȣ�ÿ�곯������ȶ�Ҫ���ӻ��ģ�
������ʿ�����������ʵ۶����Ե�������¥�����ܷ���

����һ����С����¥��ÿ����ʱ����ٹ��Ƽ�������Ⱥ򵱽�
ʥ�ϵ��ټ������߸���һ��ƫ����ٹ���Ϣ�á�����������ʿ�־�
��ǹ����ӧ�����ף��������ݣ�ɱ�����ڡ�
LONG
	);

	set("exits", ([
        "north" : __DIR__"guang2",
        "south" : __DIR__"duanmen",
	]));

	set("objects", ([
		 "/d/beijing/npc/shiwei1" : 4,
	]));

	set("outdoors","beijing");
	setup();
};

int valid_leave(object me, string dir)
{
        int i;
        if ((dir=="north") && me->query("class")!="officer" && (objectp(present("yideng shiwei", environment(me)))))
                return notify_fail("����������ǰ��ס�㣬����˵�����ʹ����أ���ֹ�����˵ȳ��룡\n");
        return ::valid_leave(me, dir);
}
