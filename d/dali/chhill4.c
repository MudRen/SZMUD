// Code of ShenZhou
// AceP
// ALN added dufeng part 4 / 98

inherit ROOM;

int do_pick(string);
int do_get(string);

void create()
{
	set("short", "�軨ɽ");
	set("long", @LONG
�����ڲ軨ɽ�ϣ�������������ïʢ�Ĳ軨����Ȼ����
���Ƿ�Ʒ����ż��Ҳ����һ�����Ʒ�������С�������Զ�Ǵ���
�ǵı��š���һЩ�����ڷ�����ȥ���ƺ����䳲(fengchao)����
�����軨���
LONG
	);

	set("exits", ([
		"south"  : __DIR__"chhill1.c",
		]));

	set("objects", ([
		__DIR__"obj/chahua" : 1,
		]));

        set("fengamount", 3 + random(3));

	set("cost", 2);
	set("outdoors", "dali");
	setup();
}

void init()
{
        object *inv;
        object me = this_player();
        object newfeng;
        int myfeng, i;


        if( interactive(me) ) {
        inv = all_inventory(this_object());
        for(i = 0; i < sizeof(inv); i++) {
                if( inv[i]->query("id") == "dufeng" ) {
                myfeng++;
                if( !inv[i]->is_fighting() ) {
                        inv[i]->add_temp("apply/attack", 30);
                        inv[i]->add_temp("apply/damage", 30);
                        COMBAT_D->do_attack(inv[i], me);
                        inv[i]->add_temp("apply/attack", -30);
                        inv[i]->add_temp("apply/damage", -30);
                        inv[i]->kill_ob(me);
                }
                }
        }

        for(i = 0; i < (query("fengamount") - myfeng); i++) {
                newfeng = new("/clone/beast/dufeng");
                newfeng->move(this_object());
                newfeng->add_temp("apply/attack", 30);
                newfeng->add_temp("apply/damage", 30);
                COMBAT_D->do_attack(newfeng, me);
                newfeng->add_temp("apply/attack", -30);
                newfeng->add_temp("apply/damage", -30);
                newfeng->kill_ob(me);
        }
        }

        add_action("do_pick", "pick");    
	add_action("do_get","get");
}

int do_pick(string arg)
{
        object me = this_player();
        object *inv = all_inventory(this_object());
        object ob;
        int myfeng, i;
         
        if( !arg || !(arg == "fengchao" || arg == "chao") )
                return 0;

        if( time() < query("lastpick") + 300 ) {
                write("���û�з䳲��\n");
                return 1;
        }

        if( me->query_temp("pickchao") ) {
                write("��һֱ��������Ѷ��䶼�����ˣ��������䳲��\n");
                return 1;
        }

        for(i = 0; i < sizeof(inv); i++ ) {
                if( inv[i]->query("id") == "dufeng" ) {
                        myfeng++;
                        inv[i]->add_temp("apply/attack", 50);
                        inv[i]->add_temp("apply/damage", 50);
                        COMBAT_D->do_attack(inv[i], me);
                        inv[i]->add_temp("apply/attack", -50);
                        inv[i]->add_temp("apply/damage", -50);
                        inv[i]->kill_ob(me);
                }
        }

        if( myfeng > 0 ) {
                write("�䳲��Χ���Ƕ��䣬�޷�ȡ������\n");
                return 1;
        }

        ob = new("/d/shenlong/obj/fengchao");
        ob->set("owner", me->query("id"));
        ob->move(me);
        set("lastpick", time());
        me->set_temp("pickchao", 1);
        message_vision("ֻ��$N�ö����ǲ��ڣ��Ͻ�ժ�·䳲���ڻ���\n", me);

        return 1;
}

int valid_leave(object me, string dir)
{
        if( me->query_temp("pickchao") )
                me->delete_temp("pickchao");

        return ::valid_leave(me, dir);
}

int do_get(string arg)
{
	object me, ob, weapon;
	me=this_player();

	if (arg=="cha" || arg=="all" || arg=="cha hua") {
		if (!objectp(ob=present("cha", environment(me)))) {
			tell_object(me, "����ûʲô��Ʒ�ֵĲ軨ֵ�����ߡ�\n");
			return 1;
		}
		if (!objectp(weapon=me->query_temp("weapon"))
			|| weapon->query("id")!="huachu") {
			tell_object(me, "��û�г��ֵĹ�������ֲ����軨��\n");
			return 1;
		}
		if (random(2)==1) {
			message_vision("$NС��������û�������軨�ĸ���������軨����������\n", me);
			ob->move(me);
		}
		else {
			message_vision("$N����ææ���ڲ軨��һ��С�İѸ��ڶ��ˣ��úõ�һ��軨�����ˡ�\n", me);
			destruct(ob);
		}
		return 1;
	}
	return 0;
}
