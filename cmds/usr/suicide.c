// Code of ShenZhou
// suicide.c
// xQin 8/00 - enable suicide for those <10k

#include <ansi.h>

inherit F_CLEAN_UP;

int slow_suicide(object);
int halt_suicide(object);
 
int main(object me, string arg)
{
        if( me->is_busy() )
                return notify_fail("����һ��������û��ɡ�\n");

        if(!arg) {
                write("������suicide -f\n");
                return 1;
        }
        if (me->query_temp("suicide_f") > 1)
        return notify_fail("��Ȼ��ô��ԥ�������������˵�ɡ�");
	if (me->query("combat_exp") > 10000)
return notify_fail("�����к���֮�£�ֻ�е���һ��������˿�����ɱ��\n");     
        if( arg!="-f") 
        return notify_fail("����������Զ��ɱ��������suicide -f\n");
        write("�����ѡ����Զ��������ɱ��ʽ�������������Ͼ���Զɾ���ˣ������\n"
              "�����������ɱ���ǲ����Իָ��ġ�ȷ���Ļ����������ı������룺");
        input_to("check_password", 1, me, 1);
        return 1;
}

private void check_password(string passwd, object me, int forever)
{
        object link_ob;
        string old_pass;

        link_ob = me->query_temp("link_ob");
        old_pass = link_ob->query("check_password");
        if( crypt(passwd, old_pass)!=old_pass ) {
                write("�������\n");
                return;
        }

        if (forever) {
                tell_object( me,
                        HIR "\n\n�����Ҫ��ɱ�ˣ�����һ���ӵ�ʱ����Ժ��(halt)������������ˣ�\n\n\n" NOR);
                me->set_temp("suicide_countdown", 30);
                me->set_temp("pending/suicide",1);
                me->start_busy((:slow_suicide:) ,(:halt_suicide:));
                message("channel:chat", HIM+"��ҥ�ԡ�"+me->query("name")+"("+me->query("id")+")"+"���ڿ����Ƿ�Ҫ��ɱ��\n"+NOR, users() );
                me->add_temp("suicide_f", 1);

        }
}

int slow_suicide(object me)
{
        object link_ob;
        int stage;

        stage = me->query_temp("suicide_countdown");

        me->add_temp("suicide_countdown", -1);
        if( stage > 1 ) {
                if( stage%5 == 0 )
                        tell_object(me, HIR "�㻹�� " + stage*2 + " ���ʱ����Ժ�ڡ�\n" NOR);
                return 1;
        }

        link_ob = me->query_temp("link_ob");
        if( !link_ob ) return 0;

        log_file("static/SUICIDE",
                sprintf("%s commits a suicide on %s\n", geteuid(me), ctime(time())) );

        seteuid(getuid());
        rm( link_ob->query_save_file() + __SAVE_EXTENSION__ );
        rm( me->query_save_file() + __SAVE_EXTENSION__ );
        write("�ðɣ�������:)��\n");
        message("channel:chat", HIM+"��ҥ�ԡ�"+me->query("name")+"("+me->query("id")+")"+"��ɱ�ˣ��Ժ�����Ҳ������������ˡ�\n"+NOR, users() );
        destruct(me);
        destruct(link_ob);
        return 0;
}

int halt_suicide(object me)
{
        me->set_temp("pending/suicide",1);
       write("�㾭��һ����˼������Ǿ��������ɹ���ʱ��������ɱ����ͷ��\n");
        return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: suicide [-f]
 
�����Ϊĳ��ԭ���㲻�����, �����ѡ����ɱ��
 
suicide -f : ��Զ�ĳ�ȥ�������, ϵͳ��Ҫ����
             ����������ȷ�����.
 
������ѡ��һ����ɱ��ʦ��������ָ��� :)
 
HELP
);
        return 1;
}
