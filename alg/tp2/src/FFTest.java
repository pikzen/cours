public class FFTest {
	public static void main(String[] args) {
		/*
		CpxTab fft = FFT_1D.FFT(new double[] {1, 2, 3, 4});
		System.out.println("FFT =============================");
		System.out.println(fft);

		CpxTab inv = FFT_1D.FFT_inverse(fft);
		System.out.println("FFT Inverse =====================");
		System.out.println(inv);

		System.out.println("Multiplication polynômes - 2 * -3");
		System.out.println("Verif ===========================");
		double[] poly = FFT_1D.multiplication_polynome_viaCoeff(new double[] {2}, new double[] {3});
		for (double pol : poly) {
			System.out.print(pol + " ");
		}
		System.out.println();

		System.out.println("FFT  ===========================");
		System.out.println(FFT_1D.multiplication_polynome_viaFFT(new double[] {2}, new double[] {3}));

		System.out.println("Multiplication polynômes - 2+X * -3+2X");
		System.out.println("Verif ===========================");
		poly = FFT_1D.multiplication_polynome_viaCoeff(new double[] {2, 1}, new double[] {-3, 2});
		for (double pol : poly) {
			System.out.print(pol + " ");
		}
		System.out.println();

		System.out.println("FFT  ===========================");
		System.out.println(FFT_1D.multiplication_polynome_viaFFT(new double[] {2, 1}, new double[] {-3, 2}));
		*/

		int n = (int)Math.pow(2, 16);
		double[] values1 = new double[n];
		for (int i = 0; i < n; i++)
			values1[i] = Math.floor(Math.random() * 10);

		double[] values2 = new double[n];
		for (int i = 0; i < n; i++)
			values2[i] = Math.floor(Math.random() * 10);

		long date1 = System.currentTimeMillis(); //on lance le chrono
		FFT_1D.multiplication_polynome_viaCoeff(values1, values2);
		long date2 = System.currentTimeMillis(); //on arrête le chrono
		System.out.println("Multiplication via coefficient : " + (date2 - date1) + " millisecondes, " + n + " éléments");

		date1 = System.currentTimeMillis(); //on lance le chrono
		FFT_1D.multiplication_polynome_viaFFT(values1, values2);
		date2 = System.currentTimeMillis(); //on arrête le chrono
		System.out.println("Multiplication via FFT : " + (date2 - date1) + " millisecondes, " + n + " éléments");
	}
}