// test.c
// writed by shadow

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg ) return notify_fail("ָ���ʽ : test <ĳ��>\n");

	if( !ob = present(arg, environment(me) ) ) return notify_fail("��ָ�����˲����ڡ�\n");

//	SKILL_D("celestial")->hit_ob(me, ob, 50, 20);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	printf("wizard level: %d   status: %s\n", wiz_level(ob), wizhood(ob));
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : test <ĳ��>

���������书���ܵ�ǿ����
HELP
    );
    return 1;
}
