// Code of ShenZhou
// jiuyin-paper.c �ֳ������澭
// 18th-Aug-2000: by yasuko

#include <ansi.h>
inherit F_UNIQUE;
inherit ITEM;

string* subject = ({
        "cuixin-zhang",
        "jiuyin-zhao",
        "feiyu-bian",
});

void create()
{
	set_name(HIW"��Ƭ"NOR, ({ "juan pian", "paper" }));
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���������ľ�Ƭ�����������д����С�֡�\n");
		set("material", "silk");
	}
	::create();
}

void init()
{
    add_action( "do_lingwu", "lingwu" );
    add_action( "do_xiulian", "xiulian" );
}

int do_lingwu(string arg)
{
	object report,*ob,me=this_player();
	int i,flag,slow=0;
        string skill;

        if (me->query_busy() > 0) return notify_fail("����æ���ء�\n");
        if (!arg) return notify_fail("���������澭�е������书��\n");
        flag=0;
	for(i=0;i<sizeof(subject);i++) {
                if (arg==subject[i]) flag=1;
        }
        if (flag==0) return notify_fail("���޷��Ӿ�Ƭ�����������书��\n");
        if (!me->query_skill(arg,1)) return notify_fail("����Ц�ˣ���������������书��\n");
        if (me->query_skill(arg,1)<=40) return notify_fail("�������ڵ��书���𣬻�û����������\n");
        switch(arg) {
                case "jiuyin-zhao":      skill="claw";
                                       	 if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                        		         return notify_fail("��������׹�צ������֡�\n");
                                         break;
                case "cuixin-zhang":     skill="strike";
                                       	 if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                        		         return notify_fail("��������Ʊ�����֡�\n");
                                         break;
                case "feiyu-bian":       skill="whip";
                                         return notify_fail("������û���������ƮƼ�ޡ�\n");
                                         break;
        }
	if ((int)me->query_skill(skill,1)*3<(int)me->query_skill(arg,1)*2)
		return notify_fail("��Ļ������в���ʵ���޷���������\n");
	if (environment(me)->query("no_fight"))	return notify_fail("����������ã��޷�ר������\n");
        ob = all_inventory(environment(me));
       	for(i=0; i<sizeof(ob); i++) {
		if ((string)ob[i]->query("race") == "����"  && ob[i] != me )
                        return notify_fail("����ʱ�����һ���ˣ�������߻���ħ�ġ�\n");
        }
	if (((int)me->query_skill(arg, 1)) %10==9&&(int)me->query_skill(arg, 1)<380)
		return notify_fail("���ƺ�������ʲô���⣬��˼������⡣��û���ȥ����ʦ���ɡ�\n");
        if (me->query("jiuyin/corpse_poison")>151740)
		return notify_fail("�㷢�־�Ƭ������������ǰ�����ķ������ྶͥ��˿������Ҫ�졣\n");
	if ((int)me->query("jing") < 50) return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("jingli") < 30) return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 20) return notify_fail("������������ˡ�\n");
	if ((int)me->query("qi") < 10) return notify_fail("�������̫���ˡ�\n");
        if (random(me->query("jiuyin/corpse_poison"))>1681) {
                slow=1;
		tell_object(me,"�㷴�������������������ʱ����ʽ��ӡ֤��ȴ�ܾ�����Щ���Ծ���\n");
        }
        me->start_busy(1);
        me->receive_damage("jing", 50+slow*50);
        me->receive_damage("jingli", 30+slow*30);
        me->add("neili", -(20+slow*20));
        me->receive_damage("qi", 10+slow*10);
        me->improve_skill(arg, (int)me->query_skill(skill,1)/(5+slow)+1);
        message_vision( "$Nһ����ϸ���Ķ��ž�Ƭ������һ�߲�ͣ�رʻ��š�\n", me);
        return 1;
}

int do_xiulian(string arg)
{
	object report,*ob,skeleton,me=this_player();
	int i,flag,tmp;
        string skill,item;

        if (me->query_busy() > 0) return notify_fail("����æ���ء�\n");
        if (!arg) return notify_fail("���������澭�е������书��\n");
        flag=0;
	for(i=0;i<sizeof(subject);i++) {
                if (arg==subject[i]) flag=1;
        }
        if (flag==0) return notify_fail("��Ƭ��û�м��������书��\n");
        if (!me->query_skill(arg,1)) return notify_fail("����Ц�ˣ���������������书��\n");
        if (me->query_skill(arg,1)<=40) return notify_fail("�������ڵ��书���𣬻�û������������\n");
        switch(arg) {
                case "jiuyin-zhao":      skill="claw";
                                       	 if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                        		         return notify_fail("���������׹�צ������֡�\n");
                                         item="skeleton";
                                         break;
                case "cuixin-zhang":     skill="strike";
                                       	 if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                        		         return notify_fail("���������Ʊ�����֡�\n");
                                         item="corpse";
                                         break;
                case "feiyu-bian":       skill="whip";
                                         return notify_fail("������û����������ƮƼ�ޡ�\n");
                                         break;
        }
	if ((int)me->query_skill(skill,1)*3<(int)me->query_skill(arg,1)*2)
		return notify_fail("��Ļ������в���ʵ���޷�����������\n");
	if (environment(me)->query("no_fight"))	return notify_fail("�������ɱ�����޷�����������\n");
	if ((int)me->query("jingli") < 30) return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 20) return notify_fail("������������������ơ�\n");
	skeleton = present(item, me);
	if (!objectp(skeleton)) {
                if (item=="corpse") return notify_fail("�����һ��ʬ�����������ơ�\n");
                if (item=="skeleton") return notify_fail("�����һЩ�������������׹�צ��\n");
        }
        ob = all_inventory(environment(me));
	tmp = 0;
       	for(i=0; i<sizeof(ob); i++) 
        {
		if ((string)ob[i]->query("race") == "����"  && ob[i] != me )
		{
			if (item=="corpse") message_vision(HIR "$N��������һ��ʬ�壬������Ҫ������ȥ����ȻƳ����Χ���ˣ����һ����\n" NOR, me);
			if (item=="skeleton") message_vision(HIR "$N��������һ�߹Ǻ���������Ҫ���²壬��ȻƳ����Χ���ˣ����һ����\n" NOR, me);
               		me->kill_ob(ob[i]);
               		ob[i]->fight_ob(me);
			tmp = 1;
		}
        }
	if (tmp) return notify_fail("����ɱ����ڣ�\n");
	if (skeleton->query("used")*500 > skeleton->query("combat_exp") ) {
                if (item=="skeleton") {
                        skeleton->set("long", "�⸱���ǵ�ͷ�ǹ��Ѿ����ѣ����Ǳ������׹�צ���顣\n");
                        return notify_fail("�⸱���ǵ�ͷ�ǹ��Ѿ����ѣ����������ˡ�\n");
                }
		if (item=="corpse") return notify_fail("���ʬ���������Ȼ���ѣ����������ˡ�\n");
	}
        if (me->query("jiuyin/corpse_poison")>151740) {
                i=random(me->query_kar());
                if (report=find_player("yasuko")) tell_object(report,sprintf("id:%s,kar:%d,i:%d\n",me->query("id"),me->query("kar"),i));
                if (i<10) {
                        tell_object(me, BLU"ͻȻһ������֮������ĵ��ﱼӿ��������������������Ҵܡ�\n"NOR);
                        if (i==3) {
                                me->set_temp("last_damage_from", "ʬ�����Ķ�����");
                                me->add("jiuyin/corpse_poison",-(int)me->query("jiuyin/corpse_poison")/100);
                                me->die();
                        }
                        else me->unconcious();
                        return 1;
                }
        }
        skeleton->add("used", 1);
        me->receive_damage("jingli", 10);
        me->add("neili", -5);
        tmp=(int)me->query_skill(skill,1)/5+3;
        me->improve_skill(arg, tmp);
        message_vision( "$N���ž�Ƭ�ϵ���ʽ��������"+skeleton->name()+"��\n" ,me);
        if (!me->query("jiuyin/corpse_poison")) me->set("jiuyin/corpse_poison",tmp);
        else me->add("jiuyin/corpse_poison",tmp);
        me->add("shen", -random(3));
        if (random(10) == 3) tell_object(me, "����������һ��а��ð����ͷ��\n");
        return 1;
}