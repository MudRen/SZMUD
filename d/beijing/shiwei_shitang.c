//Cracked by Roath
// Room: /d/beijing/shiwei_shitang.c

inherit ROOM;
#include "beijing_defs.h"

int do_eat(string);
int do_drink(string);
int vomit(object);

void create()
{
        set("short", "����ʳ��");
        set("long", @LONG
�����������ǳԷ��ĵط����͵������������������߳�
�����졣ż��Ҳ�ܿ���һЩ����Ӫ�Ĵ�١������Ϸ��˺�Щ
�Եĺȵģ��������ðɡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "west"  : __DIR__"jiaochang",
        ]));
        set("objects", ([ /* sizeof() == 4 */
        __DIR__"npc/shiwei"  : 2,
        ]));

	set("item_desc", ([
	"table" : "���Ϸ��������ͷ�ɳ� (eat)��Ҳ����ˮ�ɺ� (drink)\n",
	"����" : "���Ϸ��������ͷ�ɳ� (eat)��Ҳ����ˮ�ɺ� (drink)\n",
	"����" : "���Ϸ��������ͷ�ɳ� (eat)��Ҳ����ˮ�ɺ� (drink)\n",
        ]));
 
        set("no_clean_up", 0);
        set("cost", 2);

 
        setup();
}

void init()
{
    add_action("do_eat", "eat");
    add_action("do_drink", "drink");
}

int do_eat(string arg)
{
    object player=this_player();
    int    food, max_food;

    if (arg)
	return command("eat "+arg);

    if (player->is_busy())
	return notify_fail("����æ���ء�\n");
    food = player->query("food");
    max_food = player->max_food_capacity();

    if (food >= max_food) 
	return notify_fail("���Ѿ��Գ��ˣ���Ҫ�ԣ�\n");
    
    food += max_food/10;
    if (food > max_food) food = max_food;
    message_vision("$N�������ϵ���ͷ�������ڡ�\n", player);
    player->start_busy(2);
    player->set("food", food);

    if (!IS_SHIWEI(player) &&
	!wizardp(player)){
	message_vision("$N�����Ա�����͵͵��Ц��һ����\n", player);
	call_out("vomit", 5, player);
    }
    return 1;
}

int vomit(object player)
{
    message_vision("$NͻȻŻ���������³�������ͷ���������ʲô�������䶯��\n",
		player);
    player->set("food", 0);
    player->start_busy(5);
    return 1;
}

int do_drink(string arg)
{
    object player=this_player();
    int    water, max_water;

    if (arg)
	return command("eat "+arg);

    if (player->is_busy())
	return notify_fail("����æ���ء�\n");
    water = player->query("water");
    max_water = player->max_water_capacity();

    if (water >= max_water) 
	return notify_fail("���Ѿ��ȱ��ˣ���Ҫ�ԣ�\n");
    
    water += max_water/10;
    if (water > max_water) water = max_water;
    message_vision("$N�������ϵ�ˮ��������ڡ�\n", player);
    player->start_busy(1);
    player->set("water", water);

    if (!IS_SHIWEI(player) &&
	!wizardp(player)){
	message_vision("$N�����Ա�����͵͵��Ц��һ����\n", player);
	player->apply_condition("slumber_drug",
	    player->query_condition("slumber_drug")+100);
    }
    return 1;
}
