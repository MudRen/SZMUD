// Code of ShenZhou
// apply.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if (me->query_busy())
		return notify_fail("ʲô��\n");
	if( !arg || arg=="" ) return notify_fail("��Ҫ����ʲô��\n");

	ob = present(arg, me);
	if( !ob ) ob = present(arg, environment(me));
	if( !ob ) return notify_fail("��Ҫ����ʲô��\n");

	notify_fail("�����������ܵ�ҩ���á�\n");
	return ob->cure_ob(me);
}
