// Code of ShenZhou
// yin.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object dest;

	if(!arg) return notify_fail("��Ҫ��˭��ˮ��\n");

	if( !objectp(dest = present(arg, environment(me))) )
		return notify_fail("����û������������\n");

	if( !dest->is_character() )
		return notify_fail("ʲô��\n");

	if( dest->query("race") == "����" )
		return notify_fail("�㲻��ι�˺�ˮ��\n");

	if( dest->query_lord() != me )
		return notify_fail("�㲻���������ˣ�\n");

	if( !environment(me)->query("resource/water") )
		return notify_fail("����û��ˮԴ��\n");

	if( dest->query("water") >= dest->max_water_capacity() )
		return notify_fail("���Ѿ��ȵ�̫���ˣ���Ҳ�Ȳ����ˡ�\n");

	dest->add("water", 20);
	dest->add("jingli", 20);
	if( dest->query("jingli") > dest->query("max_jingli")) 
	dest->set("jingli", dest->query("max_jingli"));

	message_vision("$Nǣ��" + dest->name() + "��ι�������˼���ˮ��\n", me);

	if( dest->is_fighting() ) dest->start_busy(2);

	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : drink|yin <ĳ����>
 
���ָ���������ιĳ�����ˮ��
 
HELP
    );
    return 1;
}
