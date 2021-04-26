// Code of ShenZhou
// Room: /d/gaibang/undertree.c
// Date: Haa 96/03/22

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ϻ����ײ������ܹ��߻谵����Ӱ�λΣ��ƺ��м����ڰ��Ķ�������
��ߣ�ͨ������˷���һλ����ؤ�����ֵ��������еĵ��ϡ����������㷢��
ǽ���ϻ��ŷ��ֲڵ�·�߲�ͼ��map����
LONG
	);


	set("exits", ([
		"up":__DIR__"inhole",
//              "down":__DIR__"chuchang",
                     "0":__DIR__"bjandao1", 
		"1":__DIR__"xcandao1",
		"2":__DIR__"zlandao1",
		"3":__DIR__"slandao1",
		"4":__DIR__"xxandao1",
		"5":__DIR__"wdandao1",
		"6":__DIR__"qzandao1",
		"7":__DIR__"emandao1",
		"8":"/d/qilian/xsandao1",
	]));

	set("item_desc",([ "map" : 
                        "�����㣺ͨ��������\n" + 
		"����һ��ͨ����ɽ��\n" +
		"���ڶ���ͨ�����֡�\n" +
		"��������ͨ�����֡�\n" +
		"�����ģ�ͨ�����ޡ�\n" +
		"�����壺ͨ���䵱��\n" +
		"��������ͨ��Ȫ�ݡ�\n" +
		"�����ߣ�ͨ�����ҡ�\n" +
		"���ڰˣ�ͨ��ѩɽ��\n"
	]));

	set("objects",([
		CLASS_D("gaibang") + "/liang" : 1,
	]));

	set("cost", 1);
	setup();
	"/clone/board/gaibang_b"->foo();
}
int valid_leave(object me, string dir)
{
	mapping myfam;
	object *inv;
	int found, i;
	
	myfam = (mapping)me->query("family");

	if ( present("liang zhanglao", environment(me)) ) {
	    if ( (!myfam || myfam["family_name"] != "ؤ��") && dir != "up" )
		return notify_fail("�����ϵ�ס�����ȥ·��\n");

	    inv = all_inventory(me); 
	    for (i=0; i<sizeof(inv); i++) {
	        if ( inv[i]->is_container() && (present("baicao dan", inv[i]) 
	        || present("xionghuang wan", inv[i])) ) found = 1;
	    }

	    if ( present("baicao dan", me) || present("xionghuang wan", me) || found )
		return notify_fail("�����ϵ�ס����˵������ѵ�ҩ�����ٳ�ȥ�� ������ƶ񻯣�\n");
	}
	   
	return ::valid_leave(me, dir);
}
