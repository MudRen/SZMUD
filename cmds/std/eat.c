// Code of ShenZhou
// eat.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if (me->query_busy())
		return notify_fail("�����ԣ���ʲô��\n");

	if( !arg || arg=="" ) return notify_fail("��Ҫ��ʲô��\n");

	ob = present(arg, me);
	if( !ob ) ob = present(arg, environment(me));
	if( !ob ) return notify_fail("��Ҫ��ʲô��\n");

	notify_fail("�����������ܳԡ�\n");
	return ob->feed_ob(me);
}
