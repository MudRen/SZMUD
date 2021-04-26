// Code of ShenZhou
// road: /zhongnan/kitchen2.c

inherit ROOM;
int do_serve();

void create()
{
		  set("short","����");

		  set("long",@LONG
������ǳ����ˡ�ֻ��ʯ���е����Ϸ���Щ�������С�˼���ˮ��һ
��һ������������Ƥ�����ϸ�������æ��׼��ʳ������Ƕ������ϸ�
�������ţ�ֻ֪������Сʱ���ѽ������Ĺ����֪�����˶������ˡ�ǽ��
�߶�����ƿƿ�޹�(bottle)��һ�ɵ�������ζ�ӹ�����Ʈ�˳�����������
һ���ߵ���
LONG);
	set("item_desc",(["bottle" : "
�������װ��һЩ�ư�ɫ��Һ�壬���������绨�ܰ�������㳢��
һЩ��ֻ������֭Һ�������㣬���úȵġ�����ǹ�Ĺ����������佬�ˡ�
����佬�����ɵ���ʳ�����һ������ʤҩ��
					\n",]));

	set("exits",([ "south" : __DIR__"zoudao3",]));
	set("cost",1);
	set("objects",([
		"/kungfu/class/gumu/sun" : 1,
		__DIR__"obj/mitao" : 1,
		 __DIR__"obj/xiangcha" : 1,
	]));
		  setup();
}


void init()
{
        add_action("do_serve", "serve");
}



int do_serve()
{
        object ob1, ob2, *inv, me = this_player();
        int food_ind, water_ind, f, w, i;
		  mapping myfam;

        myfam = (mapping)me->query("family");
        if ( !myfam || myfam["family_name"] != "��Ĺ��" )
                return notify_fail("��Ǳ��ɵ��ӣ�������ȡʳ�\n");

        inv = all_inventory(me);
        for (i=0; i<sizeof(inv); i++) {
                if (inv[i]->query("food_supply") && inv[i]->value() >= 0) f++;
                if (inv[i]->query("drink_supply") && inv[i]->value() >= 0) w++;
        }

        food_ind = me->query("food");
        water_ind = me->query("water");

        if ( (int)me->max_food_capacity()-food_ind < 10
        && (int)me->max_water_capacity()-water_ind < 10 )
                return notify_fail("���ѳԱ����㣬���ǵȻ����Ҫ�ɣ�\n");       

        message_vision("$N����������ЦҪЩʳ��Ժȡ�\n", me);

        if ( (int)me->max_food_capacity()-food_ind >= 40 && !f
        && !present( "tao", environment(me) ) ) {
                ob1 = new(__DIR__"obj/mitao");
                ob1->move(me);
                message_vision("������Ц�������ó�"+ob1->name()+"��$N��\n", me);
        }
        else if ( (int)me->max_food_capacity()-food_ind >= 40 )
                message_vision("�����Ŷ�$N˵�����㲻���ж������𣿳�����˵�ɡ�\n", me); 
        else message_vision("�����Ŷ�$N˵������������ųԣ�̫���ɲ��á�\n", me);
        
        if ( (int)me->max_water_capacity()-water_ind >= 40 && !w 
        && !present("tea", environment(me)) ) {
                ob2 = new(__DIR__"obj/xiangcha");
                ob2->move(me);
                message_vision("������Ц�������ó�"+ob2->name()+"��$N��\n", me);
        }
        else if ( (int)me->max_water_capacity()-water_ind >= 40 )
                message_vision("�����Ŷ�$N˵�����㲻���ж������𣿺�����˵�ɡ�\n", me);
        else message_vision("�����Ŷ�$N˵������Ÿպȹ�����ô�ֿ�����\n", me);

        return 1;
}

int valid_leave(object me, string dir)
{
        object *inv;
        int i, f, w;
        
        inv = all_inventory(me);
        for (i=0; i<sizeof(inv); i++) {
                if (inv[i]->query("food_supply") && inv[i]->value() >= 0) f++;
                if (inv[i]->query("drink_supply") && inv[i]->value() >= 0) w++;
        }

        if ( f>0 || w>0 ) return notify_fail("������������˵�����ż������ǰѶ����������߰ɡ�\n");

        return ::valid_leave(me, dir);
}
     