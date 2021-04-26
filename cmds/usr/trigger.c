// trigger.c 
#include <ansi.h> 
inherit F_CLEAN_UP; 
 
int main(object me, string arg) 
{ 
        int i; 
        mapping trigger; 
        string verb, replace, *vrbs,cname; 
 
        if( !arg ) { 
                trigger = me->query_all_trigger(); 
                if( !sizeof(trigger) ) { 
                        write("��Ŀǰ��û���趨�κ� trigger��\n"); 
                        me->disable_trigger(); 
                } else  { 
                        i = me->query_trigger_enabled(); 
                        me->disable_trigger(); 
                        write("��Ŀǰ�趨�� trigger �У�\n"); 
                        vrbs = keys(trigger); 
                        for(i=0; i < sizeof(vrbs); i++) 
                                printf("%-40s ��������������:  %s\n", vrbs[i]+NOR, trigger[vrbs[i]]); 
                        write("\n��Ĵ�����Ŀǰ��"+(i?"�򿪵�":"�رյ�")+"��\n"); 
                        if( i ) me->enable_trigger(); 
                } 
                return 1; 
        } 
 
        if( arg=="on" ) 
        { 
                me->enable_trigger(); 
                write("��trigger������\n"); 
                return 1; 
        } 
        if( arg=="off" ) 
        { 
                me->disable_trigger(); 
                write("�ر�trigger������\n"); 
                return 1; 
        }                        
                cname = arg; 
                cname = replace_string(cname, "$BLK$", BLK); 
                cname = replace_string(cname, "$RED$", RED); 
                cname = replace_string(cname, "$GRN$", GRN); 
                cname = replace_string(cname, "$YEL$", YEL); 
                cname = replace_string(cname, "$BLU$", BLU); 
                cname = replace_string(cname, "$MAG$", MAG); 
                cname = replace_string(cname, "$CYN$", CYN); 
                cname = replace_string(cname, "$WHT$", WHT); 
                cname = replace_string(cname, "$HIR$", HIR); 
                cname = replace_string(cname, "$HIG$", HIG); 
                cname = replace_string(cname, "$HIY$", HIY); 
                cname = replace_string(cname, "$HIB$", HIB); 
                cname = replace_string(cname, "$HIM$", HIM); 
                cname = replace_string(cname, "$HIC$", HIC); 
                cname = replace_string(cname, "$HIW$", HIW); 
                cname = replace_string(cname, "$NOR$", NOR);          
                arg = cname; 
 
        if( sscanf(arg, "%s %s", verb, replace)!=2 ) 
                me->set_trigger(arg, 0); 
        else if( verb=="trigger" ) 
                return notify_fail("�㲻�ܽ� \"trigger\" ָ���趨Ϊ pattern ��\n"); 
        else if( verb=="" )              
                return notify_fail("��Ҫ��ʲ�� trigger��\n"); 
        else 
        { 
                return me->set_trigger(verb, replace); 
        } 
 
        write("Ok.\n"); 
        return 1; 
} 
 
int help (object me) 
{ 
        write(@HELP 
ָ���ʽ : trigger <������Ϣ> <������Ԥ��ִ�е�����>

trigger ���������첽���˹����� kill ysyysy 
���֡����������첽���˹���������ʱ��ϵͳ�Զ�ִ�� "kill ysyysy" ��
 'trigger' �󲻼Ӳ������г������е� Trigger��
 "trigger ���������첽���˹�����" ��������� Trigger�� 
 'trigger on' ������� Trigger �Ĵ�����
 'trigger off' ��ر����� Trigger �Ĵ�����
 'trigger xxxx $gag' �᲻��ʾ���а���xxxx����Ϣ��
 ���� 'trigger ������ $gag',������Ϳ������й������ӵ�һ�е���Ϣ�ˡ�

���⣬��һ������趨 set disconnect quit ���� set disconnect out��
����ϵͳ�ж���Ҷ��ߺ�����Զ�ִ�е����һ�����Ϊ�˱�������
Ƶ���б�������������� " set " ���趨��

HELP 
); 
        return 1; 
} 
