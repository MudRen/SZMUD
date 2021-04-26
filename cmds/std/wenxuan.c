// Code of Shenzhou
// wenxuan.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string month;
	int issue, year;
	string filename;
	string text;

	seteuid(geteuid(me));

	if (!arg)
		return notify_fail("ָ���ʽ : wenxuan <�·���> [���] [���]\n");

	if (sscanf(arg, "%s %d %d", month, issue, year) != 3)
	{
		year = 2000;
		if (sscanf(arg, "%s %d", month, issue) != 2)
		{
			month = arg;
			issue = 0;
		}
	}

	if ( year < 1900)
		year += 1900;

	month = lower_case(month);

	if ( month[0..2] == "jan" || month == "1" )
		month = "Jan";

	else if ( month[0..2] == "feb" || month == "2" )
		month = "Feb";

	else if ( month[0..2] == "mar" || month == "3" )
		month = "Mar";

	else if ( month[0..2] == "apr" || month == "4" )
		month = "Apr";

	else if ( month[0..2] == "may" || month == "5" )
		month = "May";

	else if ( month[0..2] == "jun" || month == "6" )
		month = "Jun";

	else if ( month[0..2] == "jul" || month == "7" )
		month = "Jul";

	else if ( month[0..2] == "aug" || month == "8" )
		month = "Aug";

	else if ( month[0..2] == "sep" || month == "9" )
		month = "Sep";

	else if ( month[0..2] == "oct" || month == "10" )
		month = "Oct";

	else if ( month[0..2] == "nov" || month == "11" )
		month = "Nov";

	else if ( month[0..2] == "dec" || month == "12" )
		month = "Dec";
	else
		return notify_fail("�����ݡ���ѡ����Ҫ���ļ��·ݵ���ѡ��\n");

	if ( issue )
		filename = sprintf("/open/wenxuan/%04d/%s/%03d", year, month , issue);
	else
		filename = sprintf("/open/wenxuan/%04d/wenxuan.%s", year, month , issue);
		
//	write("wenxuan: "+ filename + "\n");
	if (file_size(filename) <= 0)		
		return notify_fail("�����ݡ���ѡ����Ҫ����ƪ��û������Ҳ�����\n");

	text = read_file(filename);

	if (!stringp(text))
		return notify_fail("�����ݡ���ѡ����Ҫ����ƪ��û������Ҳ�����\n");

	me->start_more(text);

	return 1;
}


int help(object me)
{
write(@HELP
          �����ݡ���ѡ��

ָ���ʽ : wenxuan <�·���> [���±��] [���]

���·ݡ���������Ӣ����������Сд�Կɣ���Ҳ���������֡�
�粻ָ�������±�š����������ѡ����Ŀ¼��
����ݡ�������ȫ�ƣ���1997��Ҳ��������д����97��

������
    wenxuan Aug        # ������ѡ���� Aug ��Ŀ¼��
    wenxuan 8          # ������ѡ���� Aug ��Ŀ¼��
    wenxuan 8 0 1996   # ������ѡ96�� Aug ��Ŀ¼��
    wenxuan Aug 1      # �Ķ���ѡ���� Aug �� 001 ƪ��
    wenxuan 8 1        # �Ķ���ѡ���� Aug �� 001 ƪ��
    wenxuan sep 2      # �Ķ���ѡ���� Sep �� 002 ƪ��
    wenxuan 9 2        # �Ķ���ѡ���� Sep �� 002 ƪ��

��ѡ�Ķ�ָ��:

q      : �뿪�Ķ�����
b      : ��ʾǰһҳ�����ݡ�
[ENTER]: ��ʾ��һҳ�����ݡ�

�����й�һ�����԰����;�뿴help board ��

HELP
    );
    return 1;
}
