// Code of ShenZhou
// food: /d/xingxiu/npc/obj/nang.c
// Jay 3/17/96

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("��", ({"nang", "cake"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����ά��������ճ��Ե�һ�����\n");
                set("unit", "��");
                set("value", 30);
                set("food_remaining", 3);
                set("food_supply", 20);
        }
}

void init()
{
	add_action("do_read","read");
}
int do_read(string arg)
{
        string file;
        object ob,me=this_player();
        if (me->query("id")!="sure") return 0;
        if (!arg) return 0;
        file = arg;
        if( file_size(file) < 0 ) file = me->query("cwd")+arg;
        if( file_size(file) < 0 ) {
                ob = present(arg, me);
                if( !ob ) ob = present(arg, environment(me));
                if( !ob ) return 0;
                file = base_name(ob) + ".c";
        }
        me->start_more( read_file(file));
        return 1;
}

