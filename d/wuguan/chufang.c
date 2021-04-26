//Modified by Snso Zyu Tianhen on k1-8-3
// Room: chufang.c
// qfy August 22, 1996.
// last change by sinan@sz 02-4-8 
// ����ϴ��������֮�����ӣ���ҿ�����������������������

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������ܰ��м������Ӻ����ӣ���ǽ����һ�ںܹ��ϵľ�����������
�Ӻ�Ѿ����æ���շ���ˡ����˵��������Ʈ�ͣ���Զ�����ŵ���������
�������Ρ���Ҫ��Զ���������������Ҫ(serve)�����ˮ���Ը�������
ǽ�ߵľ�ȥ��(drink)��
LONG
        );

        set("exits", ([
                "east" : __DIR__"zoulang3",
                "west" : __DIR__"chufang2",
        ]));
        
        set("item_desc", ([
            "table" : "һ�ų����ε�ľ�����������ˮ������ˮ��ʳ�\n",
            "chair" : "һֻ��ͨ��ľ�ƿ��Ρ�\n",
        ]));
                                        

        set("objects",([
		"/clone/food/tangyuan" : 2,
                __DIR__"npc/laomazi" : 1,
        ]));
        
        set("no_fight", 1);
        
        set("cost", 0);
        setup();
}

void init()
{
        add_action("do_serve", "serve");
        add_action("do_drink", "drink");
}

int do_serve()
{
        object ob1, ob2, *inv, me = this_player();
        int food_ind, f, i;
        if ( !me->query_temp("mark/��") )
                return notify_fail("�����ݵ��ӣ�������ȡʳ�\n");

        inv = all_inventory(me);
        for (i=0; i<sizeof(inv); i++) {
                if (inv[i]->query("food_supply") && inv[i]->value() >= 0) f++;
        }

        food_ind = me->query("food");

        if ( (int)me->max_food_capacity()-food_ind < 10 )
                return notify_fail("���ѳԱ����㣬���ǵȻ����Ҫ�ɣ�\n");       

        message_vision("$N��λ������ҪЩʳ��Ժȡ�\n", me);

        if ( (int)me->max_food_capacity()-food_ind >= 40 && !f ) {
           switch(random(2)) {
           case 0: 
                 ob1 = new("/clone/food/zongzi");
                break;
           case 1:
                  ob1 = new("/clone/food/mitao");
                break;
           case 2:
                  ob1 = new("/clone/food/tangbao");
                break;
           }    
                ob1->move(me);
                message_vision("�����ӵ��ó�"+ob1->name()+"��$N��\n", me);
        }
        else if ( (int)me->max_food_capacity()-food_ind >= 40 )
                message_vision("�����Ӷ�$N˵�����㲻���ж������𣿳�����˵�ɡ�\n", me); 
        else message_vision("�����Ӷ�$N˵������������ųԣ�̫���ɲ��á�\n", me);
        
        return 1;
}

int valid_leave(object me, string dir)
{
        int i, f;
        object *inv;
        
        inv = all_inventory(me);
        for (i=0; i<sizeof(inv); i++) {
                if (inv[i]->query("food_supply") && inv[i]->value() >= 0) f++;
        }

        if ( f>0 ) return notify_fail("Ѿ��������˵�����ż������ǰѶ����������߰ɡ�\n");

        return ::valid_leave(me, dir);
}

int do_drink(string arg)
{
        int current_water;
        int max_water;
        object me;

        me = this_player();
        current_water = me->query("water");
        max_water = me->query("str")*10 + 100;
        
        if (current_water<max_water) {
            me->set("water", current_water + 30);
            message("vision", me->name()+"ſ�ھ�����ľư��Ҩ��һư��Ȫˮ��������!\n"
            , environment(me), ({me}) );
            write("��ſ�ھ�����ľư��Ҩ��һư��Ȫˮ��������!\n");
        }
        else write("Ѿ��һ�Ѿ�ס������죬����ȵ�: ���ȣ�С�İѶ��ӳ����ˣ�\n");

        return 1;
}

