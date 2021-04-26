// Code of ShenZhou
// propose.c

#include <ansi.h>
#include <dbase.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, old_app;

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

	if( !arg ) 
		return notify_fail("ָ���ʽ��propose | qiu [cancel]|<����>\n");
		
	if( arg=="cancel" ) {
		old_app = me->query_temp("marriage/propose");
		if( !objectp(old_app) )
			return notify_fail("�����ڲ�û�����κ�����顣\n");
		write("��ı����ⲻ��" + old_app->name() + "����ˡ�\n");
		tell_object(old_app, me->name() + "�ı����ⲻ��������ˡ�\n");
		me->delete_temp("marriage/propose");
		return 1;
	}

	if( !(ob = present(arg, environment(me)))
	||	!ob->is_character() )
		return notify_fail("������˭��飿\n");

	if( me->query("age") < 18 )
		return notify_fail("С���ӵ�ʲô�ң�\n");
		
	if( ob==me ) 
		return notify_fail("���Լ���飿���������ë���ɣ�\n");
		
        if( !userp(ob) )
		return notify_fail("��ֻ���������顣\n");
                        
        if( !living(ob) ) 
		return notify_fail("������Ȱ�" + ob->name() + "Ū�ѡ�\n");
		
	if( me->query("gender") == "����" || me->query("class") == "taoist" )
		return notify_fail("���׸��Ѿ���û����֪֮��ô��\n");
		
	if( me->query("gender") == "Ů��" )
		return notify_fail("Ů���Ӽ�������飬���...�����׵��ɣ�\n");
		
	if( me->query("class") == "bonze" )
		return notify_fail("�����ڷ��ţ�����֮�������Ҳ�գ�\n");

        if( me->query("class") == "lama" 
	 && me->query_skill("lamaism", 1) < 120)
		return notify_fail("Ȣ�����ӿ��Ǹ߼��������Ȩ����ȼ�������\n");
		
	if( me->is_spouse_of(ob) )
		return notify_fail("���Ѿ��޸�������\n");
	
	if( me->is_married() )
		return notify_fail("��̫̰���ˣ���һ���Ͳ������\n");
		
	old_app = me->query_temp("marriage/propose");
	if( ob==old_app )
		return notify_fail("����" + ob->name() + "��飬���ǶԷ���û�д�Ӧ��\n");
		
	if( objectp(old_app) ) {
		write("��ı����ⲻ��" + old_app->name() + "����ˡ�\n");
		tell_object(old_app, me->name() + "�ı����ⲻ��������ˡ�\n");
	}
	
	if( objectp(old_app = me->query_temp("marriage/banquet"))
	||  objectp(old_app = me->query_temp("marriage/ring")) ) {
		if( ob == old_app ) 
			return notify_fail("���Ѿ���Ӧ���ˣ�ץ��ʱ����ϯ���ָ�ɣ�\n");
			
		write("��ı����ⲻ���" + old_app->name() + "����ˡ�\n");
		tell_object(old_app, me->name() + "�ı����ⲻ��������ˡ�\n");
		me->delete_temp("marriage/banquet");
		me->delete_temp("marriage/ring");
		old_app->delete_temp("marriage/accept");
		old_app->delete_temp("marriage/ring");
	}	

	message_vision("$N��$n��顣\n", me, ob);
	me->set_temp("marriage/propose", ob );
	tell_object(ob, YEL "�����Ը����" + me->name() + "��Ϊ������ marry ָ�\n" NOR);
	if( me->query("gender") == "����" )
		tell_object(ob, YEL "�����Ⱦ����㣬�����Ǹ�����������... ������˼�����аɡ�\n" NOR);
		
	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : propose|qiu [cancel]|<����>
 
���ָ����������ĳ����飬�����ȵ��Է��� marry ָ���Ӧ����ɻ飬
Ȼ����Ů˫������һ����Ʊ��۽���ƹ����ָ���ٸ���һ����Ʊ������¥
�ϰ���ϯ����ʱ�����ϵ���Ҷ��ɵõ�һֻ��Ѽ��һƿŮ���졣���˫��
���ཻ����ָ���ϣ��������ˡ�

����Ժ���޿��Ի���ѧϰ�Ļ���˫��ʵս����ֵ����һ���󣬻����Ի�
��ѧϰ�书����ǰ�������˵���ż���ܲ���Ը�����ȫ���书�����Բ�Ҫ
���Ķ��⡣

��ο����ָ�� marry��
HELP
        );
        return 1;
}
