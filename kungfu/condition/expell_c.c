// Code of ShenZhou

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 1) {
                message_vision("���ε��ź�Ȼ���ˣ����������������µ���ʿ���˽�����\n", me);
                message_vision("��$N˵�������������������ȥ����˵�����$N���˳�ȥ��\n", me);
                me->move("/d/city/wumiao");
		message("vision",
                       HIY "ֻ�����������������µ���ʿ����һ�������������\n��"+HIY+me->name()+"˵�����������Ϊ֪�ɣ���˵�����̩ɽ�������ˡ�\n" NOR, environment(me), ({me}));

		tell_object(me, HIY "�����������ʿ�������յ�����������������������࣡\n" NOR);
		me->set("startroom", "/d/city/wumiao");
	        log_file("Expell",sprintf("[%s] %s(%s)�������ִ������ͷ�\n",ctime(time())[0..15],me->query("name"),me->query("id"))); 
		return 0;
	}
	me->apply_condition("expell_c", duration - 1);
	return 1;
}
