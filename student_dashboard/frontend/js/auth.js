document.addEventListener('DOMContentLoaded', () => {
    const toggleLink = document.getElementById('toggle-link');
    const toggleText = document.getElementById('toggle-text');
    const formTitle = document.getElementById('form-title');
    const formSubtitle = document.getElementById('form-subtitle');
    const nameGroup = document.getElementById('name-group');
    const submitBtn = document.querySelector('.primary-btn');
    const rememberMeContainer = document.getElementById('remember-me-container');
    const authForm = document.getElementById('auth-form');

    let isLogin = true;

    toggleLink.addEventListener('click', (e) => {
        e.preventDefault();
        isLogin = !isLogin;

        if (isLogin) {
            formTitle.textContent = 'Welcome Back';
            formSubtitle.textContent = 'Please enter your details to sign in.';
            nameGroup.style.display = 'none';
            submitBtn.textContent = 'Sign In';
            toggleText.textContent = "Don't have an account?";
            toggleLink.textContent = 'Sign Up';
            rememberMeContainer.style.display = 'flex';
        } else {
            formTitle.textContent = 'Create Account';
            formSubtitle.textContent = 'Join the platform to manage your studies.';
            nameGroup.style.display = 'block';
            submitBtn.textContent = 'Sign Up';
            toggleText.textContent = "Already have an account?";
            toggleLink.textContent = 'Sign In';
            rememberMeContainer.style.display = 'none';
        }
    });

    authForm.addEventListener('submit', (e) => {
        e.preventDefault();
        // Here you would normally send the data to the backend
        // For demonstration, we just redirect to the dashboard
        console.log(isLogin ? "Logging in..." : "Signing up...");
        window.location.href = 'index.html';
    });
});
