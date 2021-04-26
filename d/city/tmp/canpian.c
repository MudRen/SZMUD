// Code of ShenZhou
// canpian
// used to improve tjsg and hunyuan-yiqi over 200
// -chu@xkx

#include <ansi.h>
#include <weapon.h>

inherit ITEM;

int do_dun(string arg);
int do_jie(string arg);

void create()
{
    set_name(YEL "�����񹦲�ƪ" NOR, ({"canpian", "book"}));
    set_weight(100);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "�����䵱����ʦ���������˱�¼�Ĳ��־����񹦡�\n");
        set("material", "paper");
        set("value", 1000000000);
    }
}

int init()
{
    add_action("do_canwu", "canwu");
    return 1;
}

int do_canwu(string arg)
{
    object player = this_player();
    object target, obj=this_object(), env=environment(player);
    string my_skill, your_skill;
    int my_lvl, your_lvl;

    if (!arg) return notify_fail("��Ҫ��˭һ�����?\n");
    target = present(arg, env);
    if (!objectp(target))  return notify_fail("��Ҫ��˭һ�����?\n");
    if (!userp(target))    return notify_fail("��ֻ�ܸ����һ�����\n");
    if (player->is_busy()) return notify_fail("����æ���ء�\n");
    
    my_lvl = player->query_skill("taiji-shengong", 1);
    your_lvl = player->query_skill("hunyuan-yiqi", 1);
    if (my_lvl < 200 && your_lvl < 200) 
	return notify_fail("���̫���񹦻��߻�Ԫһ���������ߣ��޷�����\n");
    if (my_lvl >= 200) {
	my_skill = "taiji-shengong";
	your_skill = "hunyuan-yiqi";
	your_lvl = target->query_skill("hunyuan-yiqi", 1);
    }else {
	my_lvl = your_lvl;
	your_lvl = target->query_skill("taiji-shengong", 1);
	my_skill = "hunyuan-yiqi";
	your_skill = "taiji-shengong";
    }
    if (your_lvl < my_lvl-10)
	return notify_fail(target->name(1)+"�ı����ڹ�Զѷ���㣬�Ѳ��ܰ�������ˡ�\n");
    if (player->query("jing") < 1000)
	return notify_fail("�㾫�񲻼ã�������˵������ˡ�\n");
    if (target->query("jing") < 1000)
	return notify_fail("������"+target->name(1)+"����й�"+
		to_chinese(your_skill)+"�����⣬���˼�û����ɵĲ����㡣\n");
    message_vision("$N�ó������񹦲�ƪ����$n�໥����˫����������\n",
	player, target);
    player->start_busy(2+random(2));
    target->start_busy(1+random(4));
    player->add("jing", -1000);
    target->add("jing", -500);

    if (player->valid_learn(my_skill))    player->improve_skill(my_skill, 200);
    if (target->valid_learn(your_skill))  target->improve_skill(your_skill, 100);
    return 1;
}
