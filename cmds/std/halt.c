// Code of ShenZhou
// halt.c
// By Xiang@XKX (12/17/95)

int main(object me, string arg)
{
        if (me->is_fighting()) {
                me->remove_all_enemy();
                message_vision("$N�������һԾ������սȦ�����ˡ�\n", me); 
        }
        else if (!me->is_busy()) 
                return notify_fail("�����ڲ�æ��\n");
        else if ((int)me->query_temp("pending/exercise") != 0) {
                message_vision("$N���������е�����ǿ��ѹ�ص��վ��������\n", me);
                me->interrupt_me();
        }
        else if ((int)me->query_temp("pending/respirate") != 0) {
                message_vision("$N�������ڴ�����վ��������\n", me);
                me->interrupt_me();
        } 
        else if ((int)me->query_temp("pending/jingzuo") != 0) {
                message_vision("$N�ķ����ң������۾�վ��������\n", me);
                me->interrupt_me();
        }

        me->interrupt_me();
	// if (me->is_busy()) write("�����ں�æ��ͣ��������\n");
	
        return 1;
}
        
