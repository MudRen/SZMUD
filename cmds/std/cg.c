 int main(object me, string arg)
{
        if(!me->query("shenzhou/pts"))
        {
                tell_object(me, "��Ŀǰû�ж��������κι��ף�\n");
        }

        else
        {
                tell_object(me, "��Ŀǰ�����ݵĹ��׶�Ϊ " + me->query("shenzhou/pts") + " �㣡\n");
        }
        return 1;
}
