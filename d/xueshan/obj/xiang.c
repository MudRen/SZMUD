// Code of ShenZhou
#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;


mapping box = ([]);

void create()
{

		string file;
		object new_box;

        set_name("������", ({"xiang", "juan na xiang"}));
        set_weight(80000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�����˸ߵ�ľ���ӣ����Ͽ��˸���������װ�������Ǻ���ͽ�Ǿ���
�Ľ����鱦�����������ż������֣���־�ɳǣ������ҷ����\n");
                set("unit", "ֻ");
                set("material", "wood");
                set("value", 100000000);
        }

	    setup();

		box["total_value"]=0;
		box["current_value"]=0;
        file = "/data/box/xueshan.o";
        assure_file( file );

        if(file_size(file)!=-1)  {
            new_box=new("/clone/misc/save_box");
            new_box->set_owner("xueshan");
			box = new_box->query("box");
            destruct(new_box);
        }
		// set the info so zhiri lama also know
		this_object()->set("box_content",box);
        ::create();

}

int init()
{
    add_action("do_donate", "donate");
	// these two function are only for wiz now
	add_action("do_withdraw", "withdraw");
	add_action("do_reset", "reset_all");
}


int do_donate(string arg)
{

        string what, *names, name1, file;
        int amount, real_value;
        object what_ob, me, lama, new_box;

        me = this_player();

        if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
        return notify_fail("�����ʽ��donate <����> <���ҵ�λ>\n");

        what_ob = present(what + "_money", me);
        if (!what_ob)
        return notify_fail("������û�д�����Ǯ��\n");

        if (amount < 1)
        return notify_fail("���뾴�׶���" + what_ob->query("name") + "��\n");

        if ((int)what_ob->query_amount() < amount)
        return notify_fail("�����" + what_ob->query("name") + "������\n");

        // donate the Money

        what_ob->add_amount(-amount);
		real_value = what_ob->query("base_value") * amount;
      
        message_vision(sprintf("$N��������Ĳ������й�����Ͷ�ش�����ϵؽ�%s%s%s���׵��������С�\n", 
        chinese_number(amount), what_ob->query("base_unit"), 
        what_ob->query("name")), me);
		names = keys(box);
	 //	name1 = me->query("id");
        name1 = me->name(1) + "(" + me->query("id") + ")";

	    if ( member_array(name1, names) == -1 ) {
			// id not found create a new id
			box[name1] = real_value;
		}
		else {
			box[name1] += real_value;
		}
		box["total_value"] += real_value;
		box["current_value"] += real_value;

		// set the info so zhiri lama also know
		this_object()->set("box_content",box);
		// save

        new_box=new("/clone/misc/save_box");
        new_box->set_owner("xueshan");
		new_box->save_box_count(box);
        destruct(new_box);

        if (lama = present("zhiri lama", environment(this_object()))) {
			   lama->thank_doner();
		}

        return 1;

}

int do_withdraw (string arg)
{
        int amount, v;
        string what, file;
        object me, new_box;

        me = this_player();

        if (!wizardp(me)) return notify_fail("�����������أ��򲻿���\n");
        
        if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
        return notify_fail("�����ʽ��withdraw <����> <���ҵ�λ>\n");

        if (amount < 1)
        return notify_fail("�㷢������ȡ������\n");

        if (file_size("/clone/money/" + what + ".c") < 0)
        return notify_fail("����ȡ��ʲôǮ��\n");

        what = "/clone/money/" + what;
        if ((v = amount * what->query("base_value")) > box["current_value"])
              return notify_fail("���������Ǯ����ȡ��\n");

        box["current_value"] -= v;
        MONEY_D->pay_player(me, v);


		// set the info so zhiri lama also know
		this_object()->set("box_content",box);
		// save
        new_box=new("/clone/misc/save_box");
        new_box->set_owner("xueshan");
		new_box->save_box_count(box);
        destruct(new_box);

        message_vision(sprintf("$N�Ӿ�������ȡ��%s��\n", MONEY_D->money_str(v)),
                me);

        return 1;
}


int do_reset()
{
	string file;
	object new_box, me;

   	me = this_player();

    if (!wizardp(me)) return notify_fail("����Ȩʹ�ô˹��ܣ�\n");

    file = "/data/box/xueshan.o";
    assure_file( file );

    // also clear the current data
	box = ([]);

	// set the info so zhiri lama also know
	this_object()->set("box_content",box);

    if(file_size(file)!=-1)  {
            new_box=new("/clone/misc/save_box");
            new_box->set_owner("xueshan");
			new_box->reset_all_value();
            destruct(new_box);
    }

    return 1;

}

