                                              // Code of ShenZhou
// tune.c
//Piao�޸���2002-02-22������tune on�� tune off ���ܡ�
inherit F_CLEAN_UP;



int main(object me, string arg)
{

        string* wiztune = ({
                "gwiz",
                "sys",
                "alarm",
                "rumor",
                "chat",
                "sz",
                "menpai",
                "jiaoyi"
        });
        
        string* usrtune = ({
                "rumor",
                "chat",
                "sz",
                "menpai",
                "jiaoyi",
        });
        string *tuned_ch;

        tuned_ch = me->query("channels");
        if( !arg ) 
        {
                if( !pointerp(tuned_ch) || !sizeof(tuned_ch) )
                        write("�����ڲ�û�������κ�Ƶ����\n");
                else
                        write("������������Ƶ����" + implode(tuned_ch, ", ") + "��\n");
                return 1;
        }

        if(arg=="on") 
        {
                if (!wizardp(me))
                {
                        me->set("channels",usrtune);
                        write("�����ڰ�: " + implode(usrtune, ", ") + "Ƶ�������ˡ�\n");
                        return 1;
                }
                else
                {
                        me->set("channels",wiztune);
                        write("�����ڰ�: " + implode(wiztune, ", ") + "Ƶ�������ˡ�\n");
                        return 1;
                }
        }
        
        if(arg=="off") 
        {
                        me->set("channels","");
                        write("�����ڰ����е�Ƶ�����ر��ˡ�\n");
                        return 1;
        }



        if( pointerp(tuned_ch) && member_array(arg, tuned_ch)!=-1 ) {
                write("�ر� " + arg + " Ƶ����\n");
                tuned_ch -= ({ arg });
                me->set("channels", tuned_ch);
                return 1;
        } else {
                write("Ҫ��ĳ��Ƶ��ֻҪ�ø�Ƶ��˵�����ɡ�\n");
                return 1;
        }
}

int help(object me)
{
        write(@HELP
ָ���ʽ��tune [<Ƶ������>]

���ָ������ѡ���Ƿ�Ҫ����ĳһƵ����ѶϢ�����û��ָ��Ƶ�����ƣ��ͻ��г�
��Ŀǰ�����е�Ƶ�������ָ����Ƶ����ԭ�������еľͻ�ص�����֮�򿪡�

������һ��û�������е�Ƶ�����������Զ������򿪡�
Ҫ��һ��Ƶ��������ֻҪ�ã�

<Ƶ������> <ѶϢ> ....

���ӣ�
  chat hello everyone!
  
������� help channels ��ѯĿǰ����ЩƵ������������

ʹ�� tune on ����ɴ����е�Ƶ����ʹ�� tune off ����ɹر����е�Ƶ����

HELP
        );
        return 1;
}

