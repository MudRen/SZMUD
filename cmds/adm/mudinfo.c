#include <ansi.h>
inherit F_CLEAN_UP;

#define SCALE   (1.0/10.0)
#define STATUS  "ϵͳ�������д��"

string memory_expression(int m);

int count_ppls();

void create() { seteuid(getuid(this_object())); }

int main() {
        float value;
        mapping r;

        r = rusage();
        value = SCALE * (r["utime"] + r["stime"]) / uptime();

//        write("        .__________ ϵ ͳ �� Ѷ __________.\n");
        write(HIW"����������������������������������������������������\n");
        write(" Mud ��ʶ�����ƣ�  " + MUD_NAME + ".\n");
        write(" ����ϵͳ�İ汾��  " + __VERSION__ + "\n");
        write(" ϵͳ������汾��  J.H.Y.J Mudlib Ver 1.0\n");
        printf(" CPU ʹ�ðٷֱȣ�  %f %% ����� Mud ʹ����.\n", value );
        write(" CPU �ĸ���״����  " + query_load_average() + ".\n");
        printf(" ��ʹ�õļ����壺  %s bytes.\n", memory_expression(memory_info()) );
        write(" ����ʹ����������  " + sizeof( users() ) + "  ����������.\n");
        write(" ע��ʹ����������  " + count_ppls() + "  �������ڱ� Mud ע��.\n");
        write(" ��������������  " + sizeof( objects() ) + " �����.\n");
        write(" ����ִ�е�ʱ�䣺  " + CHINESE_D->chinese_period(uptime()) + "\n");
        write("����������������������������������������������������\n"NOR);        
//        write(" Mud ���ڵ�״̬��  " + STATUS + ".\n");
        return 1;
}

string memory_expression(int m)
{
        float mem;

        mem = m;
        if( mem<1024 ) return m + "";
        if( mem<1024*1024 )

                return sprintf("%.2f K", (float)mem / 1024);
        return sprintf("%.3f M", (float)mem / (1024*1024));
}

int count_ppls()
{
        int count,i;
        string *dir, *ppls;

        seteuid(getuid());

        dir = get_dir(DATA_DIR + "login/");
        for(i=0; i<sizeof(dir); i++) {
        ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
        count += sizeof(ppls);
        }
        return count;
}

int help() {

   write(@HELP
ָ���ʽ��mudinfo

���ָ�����ʾ�й���� Mud ��һЩϵͳ��Ѷ��

HELP
        );
         return 1;
}

