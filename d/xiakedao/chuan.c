//Cracked by Roath
// xiakedao/chuan.c
// modified by aln 5 / 98
// fixed bug, sdong, 10/30/98
// Modified by xQin to forbid the use of sheyao bug, 7/00

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "С��");
        set("long", @LONG
����һ�Ҳ����С��������ǿǿ�������¼����ˡ��˻�����֮�£�
֨ѽ���죬�ƺ���Ҫ�㸲����ͷ֧��һ�Ż�ɫ�����Ƿ������Ż�����
����ǰ����
LONG );

      set("exits", ([
		"out" : __DIR__"shatan",
      ]));
	set("invalid_startroom", 1);
	set("no_fight", 1);
	set("outdoors", "xiakedao" );
	setup();
//      replace_program(ROOM);

}
int valid_leave(object me, string dir)
{	object money;
	object ling1, ling2;
	object *inv;
        int found, i;
 //       if ( present(this_player()) || found )
//        return notify_fail("�㲻�ܱ�������ҳ�����\n");
        if ( present("she yao", me) || found ) 
	return notify_fail("Ϊ���������룬���ǿ����ҩ����������·�ɡ�\n");
	
	if (query("exits/out")=="/d/xiakedao/shatan3")
	{	write ("����Ҫ�´����������˵㶫���������У���һ��ԭ����Щ���Ӻ�����
���ơ���æ�򴬼ҵ�����л�����˻��֣�Ȼ���С��������ɳ̲�ϡ�\n");
//				money = new("/clone/money/silver");
//				money->set_amount(20);
//				money->move(me);
		ling1 = new("/d/xiakedao/obj/fa-ling.c");
		ling2 = new("/d/xiakedao/obj/shan-ling.c");
		ling1->move(me);
		ling2->move(me);
		ling1->set("long",
"����һ�����ƣ��Ƶ�һ����һ����������һ����š�" + me->query("name") + "��\n");
		ling1->set("owner", me->query("id"));
		ling2->set("long",
"����һ�����ƣ��Ƶ�һ����һ��Ц������һ����š�" + me->query("name") + "��\n");
		ling2->set("owner", me->query("id"));
		me->set("xkd/set", 0);   
	}

	 return ::valid_leave(me, dir);
}
